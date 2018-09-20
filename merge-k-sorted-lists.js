/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */


function comparator(a,b) {
    return a.val - b.val
}


var mergeKLists = function(lists) {
    
    
    /* Consider arrays [1,2,3], [2,3,4]. */
    /* Flatten the nested arrays and sort them all? */
    
    var flattened = [];
    
    var total_length = 0;    
    for (var i = 0; i < lists.length; i++) {
        temp = lists[i]
        while(true) {
            if (temp != null) {
                flattened.push(temp);
                temp = temp.next;
                total_length++;
            } else {
                break;
            }
        }
    }
    
    if (total_length === 0) {
        return null        
    }

    flattened.sort(comparator);
    
    for (var i = 0; i < flattened.length-1; i++) {
        flattened[i].next = flattened[i+1];
    }
    flattened[flattened.length-1].next = null;
    
    return flattened[0];

};