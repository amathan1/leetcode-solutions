package main

import "fmt"

/* Learned Golang over this weekend. Testing out what I learned. */
func main() int {

    // make a slice 
    var arr []int
    arr = make([]int, 10)
    
    for i := 0; i < 10; i++ {
        arr[i] = i+1
    }
    
    // pass by reference
    nums := productExceptSelf(arr)
    fmt.Printf("%v\n", nums)

    return 0    
}


func productExceptSelf(nums []int) []int {
    
    numZeros := 0
    prod := 1
    var index int
    
    for i:= 0; i < len(nums); i++ {
        if nums[i] == 0 {
            numZeros += 1
            index = i
        } else {
            prod *= nums[i]
        }
    }
    
    if numZeros == 0 {
        var temp int
        for i := 0; i < len(nums); i++ {
            temp = nums[i]
            nums[i] = 1
            nums[i] *= prod/temp
        }
        return nums
    } 

    else if numZeros > 1 {
        return make([]int, len(nums))
    } 

    else {
        nums = make([]int, len(nums))
        nums[index] = prod
        return nums
    }
}