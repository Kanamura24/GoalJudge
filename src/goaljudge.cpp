// -*- C++ -*-
/*!
 * @file  goaljudge.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "goaljudge.h"

// Module specification
// <rtc-template block="module_spec">
static const char* goaljudge_spec[] =
  {
    "implementation_id", "goaljudge",
    "type_name",         "goaljudge",
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
goaljudge::goaljudge(RTC::Manager* manager)
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
goaljudge::~goaljudge()
{
}



RTC::ReturnCode_t goaljudge::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("sensor_a", m_sensor_aIn);
  addInPort("sensor_b", m_sensor_bIn);
  addInPort("sensor_c", m_sensor_cIn);
  addInPort("sensor_d", m_sensor_dIn);
  
  // Set OutPort buffer
  addOutPort("finish_judge", m_finish_judgeOut);
  addOutPort("sensor_bool_a", m_sensor_bool_aOut);
  addOutPort("sensor_bool_b", m_sensor_bool_bOut);
  addOutPort("sensor_bool_c", m_sensor_bool_cOut);
  addOutPort("sensor_bool_d", m_sensor_bool_dOut);
  
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
RTC::ReturnCode_t goaljudge::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudge::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudge::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t goaljudge::onActivated(RTC::UniqueId ec_id)
{
	//判定信号の初期化
	m_sensor_bool_a.data = false;
	m_sensor_bool_aOut.write();
	m_sensor_bool_b.data = false;
	m_sensor_bool_bOut.write();
	m_sensor_bool_c.data = false;
	m_sensor_bool_cOut.write();
	m_sensor_bool_d.data = false;
	m_sensor_bool_dOut.write();
	//終了判定信号の初期化
	m_finish_judge.data = false;
	m_finish_judgeOut.write();

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t goaljudge::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t goaljudge::onExecute(RTC::UniqueId ec_id)
{
	if (m_sensor_aIn.isNew())
	{
		m_sensor_aIn.read();
		if (m_sensor_a.ranges[0] < m_sensor_threshold)
		{
			m_sensor_bool_a.data = true;
			m_sensor_bool_aOut.write();

		}
	}

	if (m_sensor_bIn.isNew())
	{
		m_sensor_bIn.read();
		if (m_sensor_b.ranges[0] < m_sensor_threshold)
		{
			m_sensor_bool_b.data = true;
			m_sensor_bool_bOut.write();
		}
	}

	if (m_sensor_cIn.isNew())
	{
		m_sensor_cIn.read();
		if (m_sensor_c.ranges[0] < m_sensor_threshold)
		{
			m_sensor_bool_c.data = true;
			m_sensor_bool_cOut.write();
		}
	}

	if (m_sensor_dIn.isNew())
	{
		m_sensor_dIn.read();
		if (m_sensor_d.ranges[0] < m_sensor_threshold)
		{
			m_sensor_bool_d.data = true;
			m_sensor_bool_dOut.write();
		}
	}

	if (m_sensor_bool_a.data == true && m_sensor_bool_b.data ==true && m_sensor_bool_c.data == true && m_sensor_bool_d.data == true)
	{
		m_finish_judge.data = true;
		m_finish_judgeOut.write();
	}
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t goaljudge::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudge::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudge::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudge::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t goaljudge::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void goaljudgeInit(RTC::Manager* manager)
  {
    coil::Properties profile(goaljudge_spec);
    manager->registerFactory(profile,
                             RTC::Create<goaljudge>,
                             RTC::Delete<goaljudge>);
  }
  
};


