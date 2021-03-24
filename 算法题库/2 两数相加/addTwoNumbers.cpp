
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
public:
    /*
        先不考虑进位，将对应的节点值相加

        然后从第一个节点开始，处理进位

    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while(1){
            p1->val += p2->val;

            if(p1->next == nullptr || p2->next == nullptr)
                break;

            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1->next == nullptr){
            p1->next = p2->next;
        }
        // 开始考虑进位
        ListNode* p = l1;
        int c = 0;
        while(p){
            p->val += c;
            if(p->val >= 10){
                p->val -= 10;
                c = 1;
                if(p->next == nullptr){
                    ListNode* t = new ListNode(1);
                    p->next = t;
                    break;
                }
            }else{
                c = 0;
            }
            p = p->next;
        }
        return l1;
    }
};