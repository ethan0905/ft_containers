/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: c2h6 <c2h6@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:20:05 by esafar            #+#    #+#             */
/*   Updated: 2023/01/12 17:52:46 by c2h6             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../std_functions/pair.hpp"

namespace ft {

	const class nullptr_t {

		public:
			template <class T>
			operator T*() const { return (0); } // T* is a pointer to T

			template <class T, class U>
			operator T U::*() const { return (0); } // U::* is a pointer to member of U

		private:
			void operator&() const;
		} NIL = {};

		// Node
		template <typename T>
		struct TreeNode {

			typedef T     value_type;

			TreeNode*   _parent;
			TreeNode*   _left;
			TreeNode*   _right;
			value_type  _value;
			bool        _is_black;

			TreeNode() : _parent(ft::NIL), _left(ft::NIL), _right(ft::NIL), _value(value_type()), _is_black(bool()) {}
			TreeNode(const value_type& value) : _parent(ft::NIL), _left(ft::NIL), _right(ft::NIL), _value(value), _is_black(bool()) {}
			TreeNode(const TreeNode& ref) : _parent(ref._parent), _left(ref._left), _right(ref._right), _value(ref._value), _is_black(ref._is_black) {}
			~TreeNode() {}

			TreeNode& operator=(const TreeNode& ref) {
				if (this != &ref) {
					_parent = ref._parent;
					_left = ref._left;
					_right = ref._right;
					_value = ref._value;
					_is_black = ref._is_black;
				}
				return (*this);
			}
	};

	template <typename NodePtr>
	bool is_left_child(const NodePtr& ptr) {
		return (ptr == ptr->_parent->_left);
	}
	template <typename NodePtr>
	bool is_right_child(const NodePtr& ptr) {
		return (ptr == ptr->_parent->_right);
	}

	template <typename NodePtr>
	bool is_black_color(const NodePtr& ptr) {
		return (ptr->_is_black);
	}
	template <typename NodePtr>
	bool is_red_color(const NodePtr& ptr) {
		return (!ptr->_is_black);
	}

	template <typename NodePtr>
	NodePtr get_min_node(NodePtr ptr, NodePtr nil) {
		while (ptr->_left != nil)
			ptr = ptr->_left;
		return (ptr);
	}
	template <typename NodePtr>
	NodePtr get_max_node(NodePtr ptr, NodePtr nil) {
		while (ptr->_right != nil)
			ptr = ptr->_right;
		return (ptr);
	}

	template <typename NodePtr>
	NodePtr get_next_node(NodePtr ptr, NodePtr nil) {
		if (ptr->_right != nil)
			return (get_min_node(ptr->_right, nil));
		while (!is_left_child(ptr))
			ptr = ptr->_parent;
		return (ptr->_parent);
	}
	template <typename NodePtr>
	NodePtr get_prev_node(NodePtr ptr, NodePtr nil) {
		if (ptr->_left != nil)
			return (get_max_node(ptr->_left, nil));
		while (!is_right_child(ptr))
			ptr = ptr->_parent;
		return (ptr->_parent);
	}

	template <typename U, typename V, class Comp>
	bool is_equal(const U& u, const V& v, Comp comp) {
		return (!comp(u, v) && !comp(v, u));
	}

	// RBTree
	template <typename U, typename V>
	class tree_iterator {

		public:
			typedef U                                                           value_type;
			typedef value_type*                                                 pointer;
			typedef value_type&                                                 reference;
			typedef V*                                                          iterator_type;
			typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
			typedef typename iterator_traits<iterator_type>::value_type         node_type;
			typedef typename iterator_traits<iterator_type>::pointer            node_pointer;
			typedef typename iterator_traits<iterator_type>::reference          node_reference;
			typedef typename iterator_traits<iterator_type>::iterator_category  iterator_category;

		private:
			node_pointer  _current;
			node_pointer  _nil;

		public:
			tree_iterator() : _current(ft::NIL), _nil(ft::NIL) {}
			tree_iterator(node_pointer cur, node_pointer nil) : _current(cur), _nil(nil) {}
			tree_iterator(const tree_iterator& ref) : _current(ref._current), _nil(ref._nil) {}
			~tree_iterator() {}

			tree_iterator& operator=(const tree_iterator& ref) {
				if (this != &ref) {
					_current = ref._current;
					_nil = ref._nil;
				}
				return (*this);
			}

			node_pointer base()       const { return (_current); }
			pointer      operator->() const { return (&_current->_value); }
			reference    operator*()  const { return (_current->_value); }

			tree_iterator& operator++() {
				_current = get_next_node(_current, _nil);
				return (*this);
			}
			tree_iterator operator++(int) {
				tree_iterator tmp(*this);
				++(*this);
				return (tmp);
			}

			tree_iterator& operator--() {
				_current = get_prev_node(_current, _nil);
				return (*this);
			}
			tree_iterator operator--(int) {
				tree_iterator tmp(*this);
				--(*this);
				return (tmp);
			}

			template <typename T>
			bool operator==(const tree_iterator<T, node_type>& x) const {
				return (_current == x.base());
			}
			template <typename T>
			bool operator!=(const tree_iterator<T, node_type>& x) const {
				return !(*this == x);
			}

			operator tree_iterator<const value_type, node_type>(void) const {
				return (tree_iterator<const value_type, node_type>(_current, _nil));
			}

			friend bool operator==(const tree_iterator& lhs, const tree_iterator& rhs) {
				return (lhs._current == rhs._current);
			}
			friend bool operator!=(const tree_iterator& lhs, const tree_iterator& rhs) {
				return (!(lhs == rhs));
			}
  	};

    template <typename Alloc>
    struct allocator_traits {
        typedef typename Alloc::value_type value_type;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;

        static Alloc allocate(Alloc& a, std::size_t n) {
            return a.allocate(n);
        }

        static void deallocate(Alloc& a, value_type* p, std::size_t n) {
            a.deallocate(p, n);
        }

		template <typename T>
		static void construct(Alloc& a, T* p, const T& val) {
			a.construct(p, val);
		}
		
		template <typename T>
		static void destroy(Alloc& a, T* p) {
			a.destroy(p);
		}		
    };

	// RBTree
	template <typename T, class Key, class Comp, class Allocator>
	class rbtree {

		public:
			typedef T                                                           value_type;
			typedef Key                                                         key_type;
			typedef Comp                                                        compare_type;
			typedef TreeNode<value_type>                                        node_type;
			typedef TreeNode<value_type>*                                       node_pointer; // node_type*
			typedef tree_iterator<value_type, node_type>                        iterator;
			typedef tree_iterator<const value_type, node_type>                  const_iterator;
			typedef Allocator                                                   allocator_type;
			typedef typename allocator_type::template rebind<node_type>::other  node_allocator;
			typedef ft::allocator_traits<node_allocator>                       node_traits;
			typedef std::size_t                                                 size_type;
			typedef std::ptrdiff_t                                              difference_type;

		private:
			node_pointer    _nil;
			node_pointer    _begin;
			node_pointer    _end;
			compare_type    _comp;
			node_allocator  _alloc;
			size_type       _size;

		public:
			rbtree(const compare_type& comp, const allocator_type& alloc) : _comp(comp), _alloc(alloc), _size(size_type()) {
				_nil = _alloc.allocate(1);
				_alloc.construct(_nil, value_type());
				_nil->_is_black = true;
				_nil->_parent = _nil;
				_nil->_left = _nil;
				_nil->_right= _nil;
				_end = create_node(value_type());
				_end->_is_black = true;
				_begin = _end;
			}
			rbtree(const rbtree& ref) : _comp(ref._comp), _alloc(ref._alloc), _size(size_type()) {
				_nil = _alloc.allocate(1);
				_alloc.construct(_nil, value_type());
				_nil->_is_black = true;
				_nil->_parent = _nil;
				_nil->_left = _nil;
				_nil->_right = _nil;
				_end = create_node(value_type());
				_end->_is_black = true;
				_begin = _end;
				insert(ref.begin(), ref.end());
			}
			~rbtree() {
				delete_node_recursive(_end);
				delete_node(_nil);
			}

			rbtree& operator=(const rbtree& ref) {
				if (this != &ref) {
					rbtree tmp(ref);
					swap(tmp);
				}
				return (*this);
			}

			// Iterators
			iterator begin() {
				return (iterator(_begin, _nil));
			}
			const_iterator begin() const {
				return (const_iterator(_begin, _nil));
			}

			iterator end() {
				return (iterator(_end, _nil));
			}
			const_iterator end() const {
				return (const_iterator(_end, _nil));
			}

			// Capacity
			bool empty() const {
				return (_size == 0);
			}

			size_type size() const {
				return (_size);
			}

			size_type max_size() const {
				return (_alloc.max_size());
			}

			// Modifiers
			ft::pair<iterator, bool> insert(const value_type& value) {
				node_pointer ptr = search_parent(value);
				
				if (ptr != _end && is_equal(ptr->_value, value, _comp))
					return (ft::make_pair(iterator(ptr, _nil), false));
				return (ft::make_pair(iterator(insert_internal(value, ptr), _nil), true));
				}
				iterator insert(iterator position, const value_type& value) {
				node_pointer ptr = search_parent(value, position.base());
				if (ptr != _end && is_equal(ptr->_value, value, _comp))
					return (iterator(ptr, _nil));
				return (iterator(insert_internal(value, ptr), _nil));
			}
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				for (; first != last; first++)
					insert(*first);
			}

			iterator erase(iterator position) {
				if (_size == 0)
					return (iterator(_nil, _nil));
				iterator tmp(position);
				++tmp;
				if (position == begin())
					_begin = tmp.base();
				--_size;
				remove_internal(position.base());
				delete_node(position.base());
				return (tmp);
			}
			size_type erase(const key_type& value) {
				iterator i(find_internal(value), _nil);
				if (i == end())
					return (0);
				if (i == begin()) {
					iterator tmp(i);
					++tmp;
					_begin = tmp.base();
				}
				--_size;
				remove_internal(i.base());
				delete_node(i.base());
				return (1);
			}
			void erase(iterator first, iterator last) {
				for (; first != last;)
					first = erase(first);
			}

			void swap(rbtree& ref) {
				std::swap(_nil, ref._nil);
				std::swap(_begin, ref._begin);
				std::swap(_end, ref._end);
				std::swap(_comp, ref._comp);
				std::swap(_alloc, ref._alloc);
				std::swap(_size, ref._size);
			}

			void clear(void) {
				rbtree tmp(_comp, _alloc);
				swap(tmp);
			}

			// Observers
			iterator find(const key_type& key) {
				return (iterator(find_internal(key), _nil));
			}
			const_iterator find(const key_type& key) const {
				return (const_iterator(find_internal(key), _nil));
			}

			iterator lower_bound(const key_type& key) {
				return (iterator(lower_bound_internal(key), _nil));
			}
			const_iterator lower_bound(const key_type& key) const {
				return (const_iterator(lower_bound_internal(key), _nil));
			}

			iterator upper_bound(const key_type& key) {
				return (iterator(upper_bound_internal(key), _nil));
			}
			const_iterator upper_bound(const key_type& key) const {
				return (const_iterator(upper_bound_internal(key), _nil));
			}

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
				return (equal_range_internal(key));
			}
			ft::pair<iterator, iterator> equal_range(const key_type& key) {
				return (equal_range_internal(key));
			}

			// Allocator
			allocator_type get_allocator() const {
				return (_alloc);
			}

		private:

			// return the node that is the parent of the node that should contain the value
			node_pointer get_root() const {
				return (_end->_left);
			}

			void set_root(const node_pointer ptr) {
				ptr->_parent = _end;
				_end->_left = ptr;
			}

			node_pointer create_node(const value_type& value) {
				node_pointer ptr = _alloc.allocate(1);
				
				_alloc.construct(ptr, value);
				ptr->_parent = _nil;
				ptr->_left = _nil;
				ptr->_right = _nil;
				ptr->_is_black = false;
				return (ptr);
			}

			void delete_node(node_pointer ptr) {
				_alloc.destroy(ptr);
				_alloc.deallocate(ptr, 1);
			}

			void delete_node_recursive(node_pointer ptr) {
				if (ptr == _nil)
					return ;
				delete_node_recursive(ptr->_left);
				delete_node_recursive(ptr->_right);
				delete_node(ptr);
			}

			node_pointer search_parent(const value_type& value, node_pointer position = ft::NIL) {
				if (position && position != _end) {
					if (_comp(value, position->_value) && position->_left == _nil) {
						iterator prev = iterator(position, _nil);
						if (prev == begin() || _comp(*--prev, value))
							return (position);
					} else if (position->_right == _nil) {
						iterator next = iterator(position, _nil);
						if (next == end() || _comp(value, *++next))
							return (position);
					}
				}
				node_pointer cur = get_root();
				node_pointer tmp = _end;
			
				for (; cur != _nil;) {
					tmp = cur;
					if (_comp(value, cur->_value))
						cur = cur->_left;
					else if (_comp(cur->_value, value))
						cur = cur->_right;
					else
						return (cur);
				}
				return (tmp);
			}

			node_pointer insert_internal(const value_type& value, node_pointer parent) {
				node_pointer ptr = create_node(value);
				
				if (parent == _end) {
					set_root(ptr);
				} else if (_comp(value, parent->_value)) {
					parent->_left = ptr;
				} else {
					parent->_right = ptr;
				}
				ptr->_parent = parent;
				insert_fixup(ptr);
				insert_update(ptr);
				return (ptr);
			}

			// insert fixup function allows to keep the tree balanced after insertion of a new node
			void insert_fixup(node_pointer ptr) {
				while (is_red_color(ptr->_parent)) {
					if (is_left_child(ptr->_parent)) {
						insert_fixup_left(ptr);
					} else {
						insert_fixup_right(ptr);
					}
				}
				get_root()->_is_black = true;
			}

			// insert fixup function for left child
			void insert_fixup_left(node_pointer& ptr) {
				node_pointer uncle = ptr->_parent->_parent->_right;
				
				if (is_red_color(uncle)) {
					ptr->_parent->_is_black = true;
					uncle->_is_black = true;
					uncle->_parent->_is_black = false;
					ptr = uncle->_parent;
				} else {
					if (is_right_child(ptr)) {
						ptr = ptr->_parent;
						rotate_left(ptr);
					}
					ptr->_parent->_is_black = true;
					ptr->_parent->_parent->_is_black = false;
					rotate_right(ptr->_parent->_parent);
				}
			}

			// insert fixup function for right child
			void insert_fixup_right(node_pointer& ptr) {
				node_pointer uncle = ptr->_parent->_parent->_left;
				
				if (is_red_color(uncle)) {
					ptr->_parent->_is_black = true;
					uncle->_is_black = true;
					uncle->_parent->_is_black = false;
					ptr = uncle->_parent;
				} else {
					if (is_left_child(ptr)) {
						ptr = ptr->_parent;
						rotate_right(ptr);
					}
					ptr->_parent->_is_black = true;
					ptr->_parent->_parent->_is_black = false;
					rotate_left(ptr->_parent->_parent);
				}
			}

			// update the begin and size of the tree after insertion
			void insert_update(const node_pointer ptr) {
				if (_begin == _end || _comp(ptr->_value, _begin->_value))
					_begin = ptr;
				_size++;
			}

			// update the begin and size of the tree after deletion
			void remove_internal(node_pointer ptr) {
				node_pointer recolor_node;
				node_pointer fixup_node = ptr;
				bool original_color = is_black_color(ptr);
				
				if (ptr->_left == _nil) {
					recolor_node = ptr->_right;
					transplant(ptr, ptr->_right);
				} else if (ptr->_right == _nil) {
					recolor_node = ptr->_left;
					transplant(ptr, ptr->_left);
				} else {
					fixup_node = get_min_node(ptr->_right, _nil);
					original_color = is_black_color(fixup_node);
					recolor_node = fixup_node->_right;
					if (fixup_node->_parent == ptr) {
						recolor_node->_parent = fixup_node;
					} else {
						transplant(fixup_node, fixup_node->_right);
						fixup_node->_right = ptr->_right;
						fixup_node->_right->_parent = fixup_node;
					}
					transplant(ptr, fixup_node);
					fixup_node->_left = ptr->_left;
					fixup_node->_left->_parent = fixup_node;
					fixup_node->_is_black = is_black_color(ptr);
				}
				if (original_color)
					remove_fixup(recolor_node);
			}

			void remove_fixup(node_pointer ptr) {
				while (ptr != get_root() && is_black_color(ptr)) {
					if (is_left_child(ptr)) {
						remove_fixup_left(ptr);
					} else {
						remove_fixup_right(ptr);
					}
				}
				ptr->_is_black = true;
			}

			void remove_fixup_left(node_pointer& ptr) {
				node_pointer sibling = ptr->_parent->_right;
				
				if (is_red_color(sibling)) {
					sibling->_is_black = true;
					ptr->_parent->_is_black = false;
					rotate_left(ptr->_parent);
					sibling = ptr->_parent->_right;
				}
				if (is_black_color(sibling->_left) && is_black_color(sibling->_right)) {
					sibling->_is_black = false;
					ptr = ptr->_parent;
				} else if (is_black_color(sibling->_right)) {
					sibling->_left->_is_black = true;
					sibling->_is_black = false;
					rotate_right(sibling);
					sibling = ptr->_parent->_right;
				}
				if (is_red_color(sibling->_right)) {
					sibling->_is_black = is_black_color(ptr->_parent);
					ptr->_parent->_is_black = true;
					sibling->_right->_is_black = true;
					rotate_left(ptr->_parent);
					ptr = get_root();
				}
			}

			void remove_fixup_right(node_pointer& ptr) {
				node_pointer sibling = ptr->_parent->_left;
				
				if (is_red_color(sibling)) {
					sibling->_is_black = true;
					ptr->_parent->_is_black = false;
					rotate_right(ptr->_parent);
					sibling = ptr->_parent->_left;
				}
				if (is_black_color(sibling->_right) && is_black_color(sibling->_left)) {
					sibling->_is_black = false;
					ptr = ptr->_parent;
				} else if (is_black_color(sibling->_left)) {
					sibling->_right->_is_black = true;
					sibling->_is_black = false;
					rotate_left(sibling);
					sibling = ptr->_parent->_left;
				}
				if (is_red_color(sibling->_left)) {
					sibling->_is_black = is_black_color(ptr->_parent);
					ptr->_parent->_is_black = true;
					sibling->_left->_is_black = true;
					rotate_right(ptr->_parent);
					ptr = get_root();
				}
			}

			void transplant(node_pointer former, node_pointer latter) {
				if (former->_parent == _end) {
					set_root(latter);
				} else if (is_left_child(former)) {
					former->_parent->_left = latter;
				} else {
					former->_parent->_right = latter;
				}
				latter->_parent = former->_parent;
			}

			// rotate nodes to left to maintain balance
			void rotate_left(node_pointer ptr) {
				node_pointer child = ptr->_right;
				
				ptr->_right = child->_left;
				if (ptr->_right != _nil) {
					ptr->_right->_parent = ptr;
				}
				node_pointer parent = ptr->_parent;
				child->_parent = parent;
				if (parent == _end) {
					set_root(child);
				} else if (is_left_child(ptr)) {
					parent->_left = child;
				} else {
					parent->_right = child;
				}
				child->_left = ptr;
				ptr->_parent = child;
			}

			// rotate nodes to right to maintain balance
			void rotate_right(node_pointer ptr) {
				node_pointer child = ptr->_left;
				
				ptr->_left = child->_right;
				if (ptr->_left != _nil) {
					ptr->_left->_parent = ptr;
				}
				node_pointer parent = ptr->_parent;
				child->_parent = parent;
				if (parent == _end) {
					set_root(child);
				} else if (is_left_child(ptr)) {
					parent->_left = child;
				} else {
					parent->_right = child;
				}
				child->_right = ptr;
				ptr->_parent = child;
			}

			// find first node of the tree
			node_pointer find_internal(const key_type& value)const {
				node_pointer ptr = get_root();
				
				while (ptr != _nil) {
					if (_comp(value, ptr->_value)) { // value < ptr->_value
						ptr = ptr->_left;
					} else if (_comp(ptr->_value, value)) { // value > ptr->_value
						ptr = ptr->_right;
					} else { // equal
						return ptr; // found
					}
				}
				return _end; // not found
			}
		
		// find the first node whose key is not less than the given key
		node_pointer lower_bound_internal(const key_type& key)const {
			node_pointer ptr = get_root();
			node_pointer tmp = _end;
			
			while (ptr != _nil) {
				if (!_comp(ptr->_value, key)) {
					tmp = ptr;
					ptr = ptr->_left;
				} else {
					ptr = ptr->_right;
				}
			}
			return tmp; 
		}

		// find the first node whose key is greater than the given key
		node_pointer upper_bound_internal(const key_type& key)const {
			node_pointer ptr = get_root();
			node_pointer tmp = _end;
			
			while (ptr != _nil) {
				if (_comp(key, ptr->_value)) {
					tmp = ptr;
					ptr = ptr->_left;
				} else {
					ptr = ptr->_right;
				}
			}
			return tmp;
		}

		ft::pair<iterator, iterator> equal_range_internal(const key_type& value) {
			node_pointer ptr = get_root();
			node_pointer tmp = _end;
			
			while (ptr != _nil) {
				if (_comp(value, ptr->_value)) { // value < ptr->_value
					tmp = ptr;
					ptr = ptr->_left;
				} else if (_comp(ptr->_value, value)) { // value > ptr->_value
					ptr = ptr->_right;
				} else { // equal
					if (ptr->_right != _nil) { // if right child exists
						tmp = get_min_node(ptr->_right, _nil); // find the min node of right subtree
					}
					return (ft::make_pair(iterator(ptr, _nil), iterator(tmp, _nil))); // return the pair of min node of right subtree + the node itself
				}
			}
			return (ft::make_pair(iterator(tmp, _nil), iterator(tmp, _nil))); // return a pair of the same node if not found
		}
		ft::pair<const_iterator, const_iterator> equal_range_internal(const key_type& value)const {
			node_pointer ptr = get_root();
			node_pointer tmp = _end;
			
			while (ptr != _nil) {
				if (_comp(value, ptr->_value)) {
					tmp = ptr;
					ptr = ptr->_left;
				} else if (_comp(ptr->_value, value)) {
					ptr = ptr->_right;
				} else {
					if (ptr->_right != _nil) {
						tmp = get_min_node(ptr->_right, _nil);
					}
					return (ft::make_pair(const_iterator(ptr, _nil), const_iterator(tmp, _nil)));
				}
			}
			return (ft::make_pair(const_iterator(tmp, _nil), const_iterator(tmp, _nil)));
		}
	};
}
