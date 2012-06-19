// -*- C++ -*-

/* main.cc
 *
 * Copyright (C) 2002 The libxml++ development team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <libxml++/libxml++.h>
#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  // Set the global C and C++ locale to the user-configured locale,
  // so we can use std::cout with UTF-8, via Glib::ustring, without exceptions.
  std::locale::global(std::locale(""));

  std::string dtdfilepath;
  if(argc > 1)
    dtdfilepath = argv[1]; //Allow the user to specify a different dtd file to use.
  else
    dtdfilepath = "example.dtd";

  int return_code = EXIT_SUCCESS;
  xmlpp::Document document;
  /* xmlpp::Element* nodeRoot = */document.create_root_node("incorrect");

  try
  {
    xmlpp::DtdValidator validator( dtdfilepath );

    try
    {
      validator.validate( &document ); // Shall fail
      std::cerr << "Validation successful (not expected)" << std::endl;
      return_code = EXIT_FAILURE;
    }
    catch( const xmlpp::validity_error& )
    {
      std::cout << "Error validating the document (expected)" << std::endl;
    }

    /* xmlpp::Element* nodeRoot2 = */document.create_root_node("example");
    xmlpp::Element * child = document.get_root_node()->add_child("examplechild");
    child->set_attribute("id", "an_id");
    child->add_child("child_of_child");

    try
    {
      xmlpp::DtdValidator validator2( dtdfilepath );
      validator2.validate( &document );
      std::cout << "Validation successful" << std::endl;
    }
    catch( const xmlpp::validity_error& )
    {
      std::cerr << "Error validating the document" << std::endl;
      return_code = EXIT_FAILURE;
    }
  }
  catch( const xmlpp::parse_error& )
  {
    std::cerr << "Error parsing the dtd" << std::endl;
    return_code = EXIT_FAILURE;
  }
  return return_code;
}

