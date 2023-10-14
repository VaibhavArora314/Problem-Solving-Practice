/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    class ex {
        toBe(v) {
            if (v !== val) throw "Not Equal";
            return true;
        }
        notToBe(v) {
            if (v === val) throw "Equal";
            return true;
        }
    }
    return new ex;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */