/*******************************************************************************
 * Copyright 2013-2014 Aerospike, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#pragma once

extern "C" {
	#include <aerospike/aerospike.h>
	#include <aerospike/as_bin.h>
	#include <aerospike/as_key.h>
	#include <aerospike/as_udf.h>
	#include <aerospike/as_scan.h>
}

#include <node.h>
#include "client.h"
using namespace node;
using namespace v8;


/*******************************************************************************
 *  CLASS
 ******************************************************************************/

class AerospikeScan: public ObjectWrap {

    /***************************************************************************
     *  PUBLIC
     **************************************************************************/

    public:
        static void Init();
        static Handle<Value> NewInstance(const Arguments& args);

		// C structure to store all the scan properties.
		as_scan scan;

		// Size of queye that's used in the scan_callback, it's user adjustable.
		int q_size;

		// stores all aerospike related information. One common structure for 
		// a client instance.
		aerospike* as;

		// Logger to log.
		LogInfo* log;
        /***************************************************************************
         *  PRIVATE
         **************************************************************************/

    private:

        AerospikeScan();
        ~AerospikeScan();

        static Persistent<Function> constructor;
        static Handle<Value> New(const Arguments& args);

        /***********************************************************************
         *  SCAN OPERATIONS
         **********************************************************************/

        /**
         * undefined scan.applyEach(udf_arg_list)
         */
        static Handle<Value> applyEach(const Arguments& args);

        /**
         *  undefined scan.foreach(callback())
         */
        static Handle<Value> foreach(const Arguments& args);
		
		/**
         *  undefined scan.select(String[])
         */
        static Handle<Value> Select(const Arguments& args);

		/**
         *  undefined scan.setPriority(SCAN_PRIORITY)
         */
        static Handle<Value> setPriority(const Arguments& args);

		/**
         *  undefined scan.setNobins(Boolean)
         */
        static Handle<Value> setNobins(const Arguments& args);

		/**
         *  undefined scan.setPercent(integer)
         */
        static Handle<Value> setPercent(const Arguments& args);

		/**
         *  undefined scan.setConcurrent(Boolean)
         */
        static Handle<Value> setConcurrent(const Arguments& args);

		/**
         *  undefined scan.setRecordQsize(integer)
         */
        static Handle<Value> setRecordQsize(const Arguments& args);

};