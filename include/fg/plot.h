/*******************************************************
 * Copyright (c) 2015-2019, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#pragma once

#include <fg/defines.h>


#ifdef __cplusplus
extern "C" {
#endif

/** \addtogroup plot_functions
 * @{
 */

/**
   Create a Plot object

   \param[out] pPlot will be set to plot handle upon creating the plot object
   \param[in] pNPoints is number of data points to display
   \param[in] pType takes one of the values of \ref fg_dtype that indicates
              the integral data type of plot data
   \param[in] pChartType dictates the dimensionality of the chart
   \param[in] pPlotType dictates the type of plot/graph,
              it can take one of the values of \ref fg_plot_type
   \param[in] pMarkerType indicates which symbol is rendered as marker. It can take one of
              the values of \ref fg_marker_type.

   \return \ref fg_err error code
 */
FGAPI fg_err fg_create_plot(fg_plot *pPlot,
                            const uint pNPoints, const fg_dtype pType,
                            const fg_chart_type pChartType,
                            const fg_plot_type pPlotType,
                            const fg_marker_type pMarkerType);

/**
   Destroy plot object

   \param[in] pPlot is the plot handle

   \return \ref fg_err error code
 */
FGAPI fg_err fg_destroy_plot(fg_plot pPlot);

/**
   Set the color of line graph(plot)

   \param[in] pPlot is the plot handle
   \param[in] pRed is Red component in range [0, 1]
   \param[in] pGreen is Green component in range [0, 1]
   \param[in] pBlue is Blue component in range [0, 1]
   \param[in] pAlpha is Blue component in range [0, 1]

   \return \ref fg_err error code
 */
FGAPI fg_err fg_set_plot_color(fg_plot pPlot,
                               const float pRed, const float pGreen,
                               const float pBlue, const float pAlpha);

/**
   Set plot legend

   \param[in] pPlot is the plot handle
   \param[in] pLegend

   \return \ref fg_err error code
 */
FGAPI fg_err fg_set_plot_legend(fg_plot pPlot, const char* pLegend);

/**
   Set global marker size

   This size will be used for rendering markers if no per vertex marker sizes are provided.
   This value defaults to 10

   \param[in] pPlot is the plot handle
   \param[in] pMarkerSize is the target marker size for scatter plots or line plots with markers

   \return \ref fg_err error code
 */
FGAPI fg_err fg_set_plot_marker_size(fg_plot pPlot, const float pMarkerSize);

/**
   Get the resource identifier for vertices buffer

   \param[out] pOut will have the buffer identifier after this function is called
   \param[in] pPlot is the plot handle

   \return \ref fg_err error code
 */
FGAPI fg_err fg_get_plot_vbo(uint* pOut, const fg_plot pPlot);

/**
   Get the resource identifier for colors buffer

   \param[out] pOut will have the buffer identifier after this function is called
   \param[in] pPlot is the plot handle

   \return \ref fg_err error code
 */
FGAPI fg_err fg_get_plot_cbo(uint* pOut, const fg_plot pPlot);

/**
   Get the resource identifier for alpha values buffer

   \param[out] pOut will have the buffer identifier after this function is called
   \param[in] pPlot is the plot handle

   \return \ref fg_err error code
 */
FGAPI fg_err fg_get_plot_abo(uint* pOut, const fg_plot pPlot);

/**
   Get the resource identifier for markers sizes buffer

   \param[out] pOut will have the buffer identifier after this function is called
   \param[in] pPlot is the plot handle

   \return \ref fg_err error code
 */
FGAPI fg_err fg_get_plot_mbo(uint* pOut, const fg_plot pPlot);

/**
   Get the vertices buffer size in bytes

   \param[out] pOut will have the buffer size in bytes after this function is called
   \param[in] pPlot is the plot handle

   \return \ref fg_err error code
 */
FGAPI fg_err fg_get_plot_vbo_size(uint* pOut, const fg_plot pPlot);

/**
   Get the colors buffer size in bytes

   \param[out] pOut will have the buffer size in bytes after this function is called
   \param[in] pPlot is the plot handle

   \return \ref fg_err error code
 */
FGAPI fg_err fg_get_plot_cbo_size(uint* pOut, const fg_plot pPlot);

/**
   Get the alpha values buffer size in bytes

   \param[out] pOut will have the buffer size in bytes after this function is called
   \param[in] pPlot is the plot handle

   \return \ref fg_err error code
 */
FGAPI fg_err fg_get_plot_abo_size(uint* pOut, const fg_plot pPlot);

/**
   Get the markers buffer size in bytes

   \param[out] pOut will have the buffer size in bytes after this function is called
   \param[in] pPlot is the plot handle

   \return \ref fg_err error code
 */
FGAPI fg_err fg_get_plot_mbo_size(uint* pOut, const fg_plot pPlot);

/** @} */

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus

namespace forge
{

/**
   \class Plot

   \brief Plot is a line graph to display two dimensional data.
 */
class Plot {
    private:
        fg_plot mValue;

    public:
        /**
           Creates a Plot object

           \param[in] pNumPoints is number of data points to display
           \param[in] pDataType takes one of the values of \ref dtype that indicates
                      the integral data type of plot data
           \param[in] pChartType dictates the dimensionality of the chart
           \param[in] pPlotType dictates the type of plot/graph,
                      it can take one of the values of \ref PlotType
           \param[in] pMarkerType indicates which symbol is rendered as marker. It can take one of
                      the values of \ref MarkerType.
         */
        FGAPI Plot(const uint pNumPoints, const dtype pDataType, const ChartType pChartType,
                   const PlotType pPlotType=FG_PLOT_LINE, const MarkerType pMarkerType=FG_MARKER_NONE);

        /**
           Copy constructor for Plot

           \param[in] pOther is the Plot of which we make a copy of.
         */
        FGAPI Plot(const Plot& pOther);

        /**
           Plot Destructor
         */
        FGAPI ~Plot();

        /**
           Set the color of line graph(plot)

           \param[in] pColor takes values of forge::Color to define plot color
        */
        FGAPI void setColor(const forge::Color pColor);

        /**
           Set the color of line graph(plot)

           \param[in] pRed is Red component in range [0, 1]
           \param[in] pGreen is Green component in range [0, 1]
           \param[in] pBlue is Blue component in range [0, 1]
           \param[in] pAlpha is Blue component in range [0, 1]
         */
        FGAPI void setColor(const float pRed, const float pGreen,
                            const float pBlue, const float pAlpha);

        /**
           Set plot legend

           \param[in] pLegend
         */
        FGAPI void setLegend(const char* pLegend);

        /**
           Set global marker size

           This size will be used for rendering markers if no per vertex marker sizes are provided.
           This value defaults to 10

           \param[in] pMarkerSize is the target marker size for scatter plots or line plots with markers
         */
        FGAPI void setMarkerSize(const float pMarkerSize);

        /**
           Get the OpenGL buffer object identifier for vertices

           \return OpenGL VBO resource id.
         */
        FGAPI uint vertices() const;

        /**
           Get the OpenGL buffer object identifier for color values per vertex

           \return OpenGL VBO resource id.
         */
        FGAPI uint colors() const;

        /**
           Get the OpenGL buffer object identifier for alpha values per vertex

           \return OpenGL VBO resource id.
         */
        FGAPI uint alphas() const;

        /**
           Get the OpenGL buffer object identifier for markers sizes, per vertex

           \return OpenGL VBO resource id.
         */
        FGAPI uint markers() const;

        /**
           Get the OpenGL Vertex Buffer Object resource size

           \return vertex buffer object size in bytes
         */
        FGAPI uint verticesSize() const;

        /**
           Get the OpenGL colors Buffer Object resource size

           \return colors buffer object size in bytes
         */
        FGAPI uint colorsSize() const;

        /**
           Get the OpenGL alpha Buffer Object resource size

           \return alpha buffer object size in bytes
         */
        FGAPI uint alphasSize() const;

        /**
           Get the OpenGL markers Buffer Object resource size

           \return alpha buffer object size in bytes
         */
        FGAPI uint markersSize() const;

        /**
           Get the handle to internal implementation of plot
         */
        FGAPI fg_plot get() const;
};

}

#endif
