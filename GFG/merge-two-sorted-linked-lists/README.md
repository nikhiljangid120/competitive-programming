# merge-two-sorted-linked-lists

- **Platform:** GFG
- **Language:** Python

## Solution

```py
class Solution:
    def sortedMerge(self, head1, head2):
        # code here
        
        dummy = Node(-1)
        curr = dummy
        
        while head1 and head2:
            if head1.data < head2.data:
                nxt = head1.next
                curr.next = head1
                head1.next = None
                head1 = nxt
                curr = curr.next
            
            else:
                nxt = head2.next
                curr.next = head2
                head2.next = None
                head2 = nxt
                curr = curr.next
                
        while head1:
            curr.next = head1
            curr = curr.next
            head1 = head1.next
        
        while head2:
            curr.next = head2
            curr = curr.next
            head2 = head2.next
            
        return dummy.next
```
