// -*- C++ -*-
/*!
 * @file  CommonImageToRTCImage.cpp
 * @brief ImageFormat Converter
 * @date $Date$
 *
 * $Id$
 */

#include "CommonImageToRTCImage.h"

// Module specification
// <rtc-template block="module_spec">
static const char* commonimagetortcimage_spec[] =
  {
    "implementation_id", "CommonImageToRTCImage",
    "type_name",         "CommonImageToRTCImage",
    "description",       "ImageFormat Converter",
    "version",           "1.0.0",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "ImageProcessin",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
CommonImageToRTCImage::CommonImageToRTCImage(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_commonImageIn("commonImage", m_commonImage),
    m_rtcImageOut("rtcImage", m_rtcImage)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
CommonImageToRTCImage::~CommonImageToRTCImage()
{
}



RTC::ReturnCode_t CommonImageToRTCImage::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("commonImage", m_commonImageIn);

  m_commonImageIn.addConnectorDataListener(ON_BUFFER_WRITE,
	  new DataListener(this));
  // Set OutPort buffer
  addOutPort("rtcImage", m_rtcImageOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t CommonImageToRTCImage::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t CommonImageToRTCImage::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void CommonImageToRTCImageInit(RTC::Manager* manager)
  {
    coil::Properties profile(commonimagetortcimage_spec);
    manager->registerFactory(profile,
                             RTC::Create<CommonImageToRTCImage>,
                             RTC::Delete<CommonImageToRTCImage>);
  }
  
};


