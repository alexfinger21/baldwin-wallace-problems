/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */

function binSearch(goal, arr) {
    let l = 0, r = arr.length - 1

    while (l < r) {
        const mid = (r + l) >> 1

        if (arr[mid] > goal) {
            r = mid-1
        } else if (mid < r && arr[mid+1] <= goal) {
            l = mid + 1
        } else {
            return r
        }
    }

    return r
}

var findMedianSortedArrays = function(nums1, nums2) {
    const big = nums1.length > nums2.length ? nums1 : nums2 
    const small = nums1.length > nums2.length ? nums2 : nums1

    const med = (big.length + small.length) >> 1 + 1

    let l = 0, r = big.length - 1

    while (l < r) {
        const mid = (l + r) >> 1

        const idx = binSearch(big[mid], small)
        console.log(mid, idx)
        if (mid + idx + 2 > med) {
            r = mid
        } else if (mid + idx + 2 < med) {
            l = mid+1
        } else {
            if ((big.length + small.length) % 2) {
                return big[mid]
            }

            return big[mid] + Math.max((idx >= 0 ? small[idx] : big[mid-1]) + (mid > 0 ? big[mid-1] : small[idx]))
        }
    }

    l = 0, r = small.length - 1

    while (l < r) {
        const mid = (l + r) >> 1

        const idx = binSearch(small[mid], big)
        console.log(mid, idx)
        if (mid + idx + 2 > med) {
            r = mid
        } else if (mid + idx + 2 < med) {
            l = mid+1
        } else {
            if ((big.length + small.length) % 2) {
                return small[mid]
            }

            return small[mid] + Math.max((idx >= 0 ? big[idx] : small[mid-1]) + (mid > 0 ? small[mid-1] : big[idx]))
        }
    }
    return 0
}

console.log("RES", findMedianSortedArrays([1, 3], [2]))
