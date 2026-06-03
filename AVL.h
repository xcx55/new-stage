#pragma once
using namespace std;
#include<iostream>

template<class K, class V>
struct AVLtreenode {
	AVLtreenode* _parent;
	AVLtreenode* _left;
	AVLtreenode* _right;
	pair<K, V> _kv;
	int _bf;
	AVLtreenode(const pair<K, V>& kv)
		:_kv(kv)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, _bf(0)
	{
	}
};

template<class K, class V>
class AVLtree {
public:
	typedef AVLtreenode<K, V> Node;
	bool insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = cur;
		while (cur) {
			if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		if (parent->_kv.first < kv.first) {
			parent->_right = new Node(kv);
			parent->_right->_parent = parent;
			cur = parent->_right;
		}
		else {
			parent->_left = new Node(kv);
			parent->_left->_parent = parent;
			cur = parent->_left;
		}
		cur->_bf = 0;
		while (parent) {
			if (parent->_left == cur) {
				--parent->_bf;
			}
			else {
				++parent->_bf;
			}
			if (parent->_bf==0) {
				break;
			}
			if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) {
				if (cur->_bf == -1 && parent->_bf == -2) {
					RotateR(parent);
				}
				else if (cur->_bf == 1 && parent->_bf == 2) {
					RotateL(parent);
				}
				else if (cur->_bf == 1 && parent->_bf == -2) {
					RotateLR(parent);
				}
				else if (cur->_bf == -1 && parent->_bf == 2) {
					RotateRL(parent);
				}
				break;
			}
		}
		return true;

	}

	void InOrder() {
		ggg(_root);
	}
	void ggg(Node* parent) {
		if (parent == nullptr)
			return;
		ggg(parent->_left);
		cout << parent->_kv.second << " ";
		ggg(parent->_right);
	}
private:
	void RotateLR(Node* parent) {
		Node* subl = parent->_left;
		Node* sublr = subl->_right;
		int bf = sublr->_bf;
		RotateL (subl);
		RotateR(parent);
		if (bf==-1) {
			subl->_bf = 0;
			parent->_bf = 1;
			sublr->_bf = 0;
		}
		else if (bf == 1) {
			subl->_bf = -1;
			parent->_bf = 0;
			sublr->_bf = 0;
		}
		else {
			subl->_bf = 0;
			parent->_bf = 0;
			sublr->_bf = 0;
		}
	}
	void RotateRL(Node* parent) {
		Node* subr = parent->_right;
		Node* subrl = subr->_left;
		int bf = subrl->_bf;
		RotateR(subr);
		RotateL(parent);
		if (bf==-1) {
			subr->_bf = 1;
			parent->_bf = 0;
			subrl->_bf = 0;
		}
		else if (bf==1) {
			subr->_bf = 0;
			parent->_bf = -1;
			subrl->_bf = 0;
		}
		else {
			subr->_bf = 0;
			parent->_bf = 0;
			subrl->_bf = 0;
		}
	}
	void RotateR(Node* parent) {
		Node* subl = parent->_left;
		Node* sublr = subl->_right;
		Node* pparent = parent->_parent;
		parent->_left = sublr;
		if (sublr)
			sublr->_parent = parent;
		subl->_right = parent;
		parent->_parent = subl;
		subl->_parent = pparent;
		if (_root == parent) {
			_root = subl;
			subl->_parent = nullptr;
		}
		else {
			if (pparent->_left == parent) {
				pparent->_left = subl;
			}
			else {
				pparent->_right = subl;
			}
		}
		parent->_bf = subl->_bf = 0;
	}
	void RotateL(Node* parent) {
		Node* subr = parent->_right;
		Node* subrl = subr->_left;
		Node* pparent = parent->_parent;
		parent->_right = subrl;
		if (subrl)
			subrl->_parent = parent;
		subr->_left = parent;
		parent->_parent = subr;
		subr->_parent = pparent;
		if (_root == parent) {
			_root = subr;
			subr->_parent = nullptr;
		}
		else {
			if (pparent->_left == parent) {
				pparent->_left = subr;
			}
			else {
				pparent->_right = subr;
			}
		}
		parent->_bf = subr->_bf = 0;
	}
	Node* _root = nullptr;
};