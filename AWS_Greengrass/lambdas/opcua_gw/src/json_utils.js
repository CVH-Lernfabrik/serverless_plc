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
 * @param {Object} obj          - Object / JSON structure to filter
 * @param {String} path         - Absolute path to the object to retrieve
 * @param {Object} defaultValue - Default return value in case the operation
 *                                fails (e.g. because of a faulty path)
 *
 * @returns {Object}            - Specified object resp. default return value
 */
JSON.getObjectByPath = function (obj, path, defaultValue) {
    if (!obj) {
        return defaultValue;
    }
    if ( !path
        || (path.length == 0)
    ) {
        return obj;
    }

    // Resolve the path in case it was specified in form of an array index or a
    // concatenated string
    if ( typeof path === 'number' ) {
        path = [path];
    }
    if ( typeof path === 'string' ) {
        return JSON.getObjectByPath(obj, path.split('.'), defaultValue);
    }

    // Get the next path element
    var key = path[0];
    var intKey = parseInt(key);
    if ( intKey.toString() === key ) {
        key = intKey;
    }

    // Get the nested object specified by the current path element
    if ( ((typeof prop === 'number') && Array.isArray(obj))
        || Object.prototype.hasOwnProperty.call(obj, key)
    ) {
        var nextObj = obj[key];
    }
    if (nextObj === void 0) {
        return defaultValue;
    }

    // Return the object specified by the given path
    if ( path.length === 1 ) {
        return nextObj;
    }

    // Recursively pass through the object until either the destination or a
    // "dead end" are reached
    return JSON.getObjectByPath(nextObj, path.slice(1), defaultValue);
};

/*
 * Description: Creates a JSON object from a given path
 *
 * @param {String} path     - Hierarchical structure of the JSON object
 * @param {Object} value    - Value to assign to the innermost element of
 *                            the JSON object to create
 *
 * @returns {Object}        - JSON equivalent of the specified path
 */
JSON.createObjectFromPath = function (path, value) {
    if ( !path
        || (path.length == 0)
    ) {
        return '{}';
    }

    // Resolve the path in case it was specified in form of a concatenated string
    if ( typeof path === 'string' ) {
        return JSON.createObjectFromPath(path.split('.'), value);
    }

    var json_string = '{"';
    json_string = json_string.concat( path.join('":{"') + '":' + value);
    for (let i = 0; i < path.length; i++) {
        json_string = json_string.concat('}');
    }

    return JSON.parse(json_string);
}

//----------
// Exports:
//----------

module.exports = {
    JSON
};
