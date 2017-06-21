#pragma once
 template
<typename T>
class ListNode
 {
 public:
	 ListNode() {};
	 ~ListNode() {};
	
	 //----------------------------------------------------------------------------------------------------
	 //Only contains what each list node requires, doesnt need functions only pointers and the actual data
	 //----------------------------------------------------------------------------------------------------

	 T Data;
	 ListNode* next;
	 ListNode* prev;
 };