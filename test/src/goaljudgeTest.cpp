// -*- C++ -*-
/*!
 * @file  goaljudgeTest.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "goaljudgeTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* goaljudge_spec[] =
  {
    "implementation_id", "goaljudgeTest",
    "type_name",         "goaljudgeTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.sensor_threshold", "0.3",

    // Widget
    "conf.__widget__.sensor_threshold", "text",
    // Constraints

    "conf.__type__.sensor_threshold", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
goaljudgeTest::goaljudgeTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_sensor_aIn("sensor_a", m_sensor_a),
    m_sensor_bIn("sensor_b", m_sensor_b),
    m_sensor_cIn("sensor_c", m_sensor_c),
    m_sensor_dIn("sensor_d", m_sensor_d),
    m_finish_judgeOut("finish_judge", m_finish_judge),
    m_sensor_bool_aOut("sensor_bool_a", m_sensor_bool_a),
    m_sensor_bool_bOut("sensor_bool_b", m_sensor_bool_b),
    m_sensor_bool_cOut("sensor_bool_c", m_sensor_bool_c),
    m_sensor_bool_dOut("sensor_bool_d", m_sensor_bool_d)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
goaljudgeTest::~goaljudgeTest()
{
}



RTC::ReturnCode_t goaljudgeTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("finish_judge", m_finish_judgeIn);
  addInPort("sensor_bool_a", m_sensor_bool_aIn);
  addInPort("sensor_bool_b", m_sensor_bool_bIn);
  addInPort("sensor_bool_c", m_sensor_bool_cIn);
  addInPort("sensor_bool_d", m_sensor_bool_dIn);
  
  // Set OutPort buffer
  addOutPort("sensor_a", m_sensor_aOut);
  addOutPort("sensor_b", m_sensor_bOut);
  addOutPort("sensor_c", m_sensor_cOut);
  addOutPort("sensor_d", m_sensor_dOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("sensor_threshold", m_sensor_threshold, "0.3");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t goaljudgeTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudgeTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudgeTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t goaljudgeTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t goaljudgeTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t goaljudgeTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t goaljudgeTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudgeTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudgeTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudgeTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudgeTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void goaljudgeTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(goaljudge_spec);
    manager->registerFactory(profile,
                             RTC::Create<goaljudgeTest>,
                             RTC::Delete<goaljudgeTest>);
  }
  
};


