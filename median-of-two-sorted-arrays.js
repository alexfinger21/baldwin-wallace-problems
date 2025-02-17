/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let i1 = 0, i2 = 0;
    const len = (nums1.length + nums2.length)

    let prev = 0
    let cur = 0

    for (let i = 0; i<=len >> 1; ++i) {
        prev = cur
        if ((i1 < nums1.length) && (i2 == nums2.length || nums1[i1] < nums2[i2])) {
            cur = nums1[i1]
            ++i1
        } else {
            cur = nums2[i2]
            ++i2
        }
    }

    return len % 2 ? cur : ((cur + prev)/2)
};
