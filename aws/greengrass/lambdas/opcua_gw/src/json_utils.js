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
    // "dead end" (innermost layer, no further subojects) are reached
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

    // Generate the string representation of the JSON structure
    var json_string = '{"';
    json_string = json_string.concat( path.join('":{"') + '":' + value);
    for (let i = 0; i < path.length; i++) {
        json_string = json_string.concat('}');
    }

    return JSON.parse(json_string);
}

/*
 * Description: Generates the path representation of a given JSON object
 *
 * @param {Object} obj      - Object / JSON structure to generate the path
 *                            representation of
 * @param {String} path     - Hierarchical structure of the JSON object
 *
 * @returns {Object}        - Unique hierarchical path representation of each
 *                            nested element in the JSON structure as well as
 *                            the associated values
 */
JSON.objectToPath = function (obj, path) {
    if ( !obj
        || (typeof obj !== 'object')
    ) {
        return {[path]: obj};
    }

    // Obtain the keys of the subobjects on the current layer of the JSON structure
    var keys = Object.keys(obj);
    if (keys.length == 0) {
        return {[path]: obj};
    }
    else {
        var pathArr = {};
        for (var key in keys) {
            // Append the keys as the unique identifiers for the subobjects to
            // the path
            var p = path ? path.concat('.') : '';
            p = p.concat(keys[key]);

            // Recursively pass through the object until a "dead end" (innermost
            // layer, no further subojects) is reached and aggregate the paths
            Object.assign( pathArr, JSON.objectToPath(obj[keys[key]], p) );
        }
        return pathArr;
    }
}

//----------
// Exports:
//----------

module.exports = {
    JSON
};
