#pragma once
 template
<typename T>
class ListNode
 {
 public:
	 ListNode() {};
	 ~ListNode() {};
	
	 T Data;
	 ListNode* next;
	 ListNode* prev;
 };