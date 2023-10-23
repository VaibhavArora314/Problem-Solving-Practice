/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let i=0;
    const ans = [];
    while (i < arr.length) {
        if (i+size < arr.length) ans.push(arr.slice(i,i+size));
        else ans.push(arr.slice(i,arr.length));
        
        i += size;
    }
    return ans;
};
