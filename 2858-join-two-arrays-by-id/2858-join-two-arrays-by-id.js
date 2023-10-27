/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    arr1.sort((a,b) => a.id-b.id);
    arr2.sort((a,b) => a.id-b.id);

    const ans = [];
    let i=0,j=0;

    while (i < arr1.length && j < arr2.length) {
        if (arr1[i].id < arr2[j].id) ans.push(arr1[i++]);
        else if (arr1[i].id > arr2[j].id) ans.push(arr2[j++]);
        else {
            ans.push(arr1[i++]);

            for (let key of Object.keys(arr2[j])) ans[ans.length-1][key] = arr2[j][key];
            j++;
        }
    }

    while (i < arr1.length) ans.push(arr1[i++]);
    while (j < arr2.length) ans.push(arr2[j++]);

    return ans;
};