/**
 * @param {number[]} nums
 * @return {void}
 */
var ArrayWrapper = function(nums) {
    this.nums = nums;
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    let sum=0;
    for (let item of this.nums) {
        sum += item;
    }
    return sum;
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    let ans = "[";
    for (let item of this.nums) {
        ans += item + ",";
    }
    if (ans.length > 1)ans = ans.slice(0,-1);
    ans += "]";
    return ans;
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */