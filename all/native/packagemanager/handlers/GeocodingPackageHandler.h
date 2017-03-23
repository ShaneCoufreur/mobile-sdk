/*
 * Copyright (c) 2016 CartoDB. All rights reserved.
 * Copying and using this code is allowed only according
 * to license terms, as given in https://cartodb.com/terms/
 */

#ifndef _CARTO_GEOCODINGPACKAGEHANDLER_H_
#define _CARTO_GEOCODINGPACKAGEHANDLER_H_

#include "packagemanager/handlers/PackageHandler.h"

namespace sqlite3pp {
    class database;
}

namespace carto {
    
    class GeocodingPackageHandler : public PackageHandler {
    public:
        explicit GeocodingPackageHandler(const std::string& fileName);
        virtual ~GeocodingPackageHandler();

        std::shared_ptr<sqlite3pp::database> getGeocodingDatabase();

        virtual void importPackage();

        virtual std::shared_ptr<PackageTileMask> calculateTileMask() const;

    private:
        std::shared_ptr<sqlite3pp::database> _database;
    };
    
}

#endif