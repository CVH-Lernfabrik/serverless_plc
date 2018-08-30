// json_utils.js
// Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
// License: Apache License Version 2.0
//
// 2018-08-30
//
// Description: Additional utility functions for parsing JSON objects

//------------
// Functions:
//------------

/*
 * Description: Retrieve a nested object from a JSON structure by its path
 *
 * @param {Object} obj      - Object / JSON structure to filter
 * @param {String} path     - Absolute path to the object to retrieve
 * @param {Object} default  - Default return value in case the operation fails
 *                            (e.g. because of a faulty path)
 *
 * @returns {Object}        - Status / Return code of the write operation
 */
function getObjectByPath (obj, path, default) {
    if (!obj) {
      return default;
    }
    if ( !path
        || (path.length === 0)
    ) {
      return obj;
    }

    // Resolve the path in case it was specified in form of an array index or a
    // concatenated string
    if (typeof path === 'number') {
      path = [path];
    }
    if (typeof path === 'string') {
      return getObjectByPath(obj, path.split('.'), default);
    }

    // Get the next path element
    var key = path[0];
    var intKey = parseInt(key);
    if (intKey.toString() === key) {
      key = intKey;
    }

    // Get the nested object specified by the current path element
    if ( ( (typeof prop === 'number') && Array.isArray(obj) )
        || Object.prototype.hasOwnProperty.call(obj, key)
    ) {
        var nextObj = obj[key];
    }
    if (nextObj === void 0) {
      return default;
    }

    // Return the object specified by the given path
    if (path.length === 1) {
      return nextObj;
    }

    // Recursively pass through the object until either the destination or a
    // "dead end" are reached
    return getObjectByPath(nextObj, path.slice(1), defaultValue);
  };

//----------
// Exports:
//----------

module.exports = {
     JSON.getObjectByPath: getObjectByPath
};
