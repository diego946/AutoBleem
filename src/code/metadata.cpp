//
// Created by screemer on 2018-12-16.
//

#include "metadata.h"
#include "database.h"

static const char *jDatabases[] = {"coversU.db", "coversP.db", "coversJ.db"};

bool Metadata::lookup(string serial) {
    for (int i = 0; i < 3; i++) {
        Database *db = new Database();
        if (db->connect(jDatabases[i])) {
            if (db->querySerial(serial, this)) {
                db->disconnect();
                switch(i)
                {
                    case 0:
                        this->lastRegion="U";
                        break;
                    case 1:
                        this->lastRegion="P";
                        break;
                    case 2:
                        this->lastRegion="J";
                        break;
                }
                return true;
            }
        };
        db->disconnect();
    }
    return false;
}