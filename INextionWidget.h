/*! \file */

#ifndef __NEONEXTION_INEXTIONWIDGET
#define __NEONEXTION_INEXTIONWIDGET

#include "NeoNextion.h"

/*!
 * \class INextionWidget
 * \brief Abstract class for all UI widgets.
 *
 * Widget objects act as a adapter/API for the widgets defined in the Nextion
 * Editor software.
 */
class INextionWidget
{
public:
  INextionWidget(Nextion &nex, uint8_t page, uint8_t component,
                 const char *name);

  uint8_t getPageID();
  uint8_t getComponentID();

  bool setNumberProperty(char *propertyName, uint32_t value);
  bool setPropertyCommand(char *command, uint32_t value);
  uint32_t getNumberProperty(char *propertyName);
  bool setStringProperty(char *propertyName, char *value);
  size_t getStringProperty(char *propertyName, char *value, size_t len);
  bool show();
  bool hide();

protected:
  bool sendCommand(char *commandStr, bool checkComplete = true);
  
protected:
  Nextion &m_nextion;    //!< Reference to the Nextion driver
  uint8_t m_pageID;      //!< ID of page this widget is on
  uint8_t m_componentID; //!< Component ID of this widget
  const char *m_name;    //!< Name of this widget
};

#endif
