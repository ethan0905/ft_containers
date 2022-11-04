# ft_containers 📦📦📦 [![esafar's 42 ft_containers Score](https://badge42.vercel.app/api/v2/cl6l739qg00490gialxmtgsrk/project/2852806)](https://github.com/JaeSeoKim/badge42)
  
## Containers/Algorithm/Iterators 📚🔢📐  
#### In C++ STL (Standard Template Library), 3 things are meaningful and important:  
  
**1. Containers:** These are used to manage collection of objects of a certain kind. Containers can be of two types: Sequence Containers (vector, deque, list) and Associative Containers (Set, Multiset, Map, Multimap).  
**2. Algorithms:** These are used to process the elements of a collection. That is algorithms feed from containers and process those elements in a predefined way and may also push the results into the same/different container.  
**3. Iterator:** These are used to step through the elements of collection of objects (aka containers).  
  
## Strat for ft_containers ⏱️  
  
1. Start by coding all std functions asked in the subject (you gonna be able to use them later, inside your containers)
- equal
- lexicographical_compare
- is_integral
- pair
- make_pair
- enable_if
- iterator_traits
- reverse_iterator
2. Then, begin coding stack as your first container using original vector from STL.  
3. When your stack container works properly. start coding vector container and test it with your stack container.  
4. Final step, code map and drop a star on this repo for the time I saved you ;)    
  
## Tools (typedef, explicit, friend)  
  
**1. typedef:** allows to give a new name to an existing data type.  
```
template <class T, ...>
class stack {
	public:
		typedef T value_type;
		
		value_type& top() {
   			return (_container.back());
		}
	[...]
};
```
**2. explicit:** allows only direct-initialization (avoid implicit conversions and copy initialization from braced-init-list).  
```
template <class T, class Container>
class stack {
	private:
		Container _container;
	public:
		explicit stack(const Container &ctnr) : _container(ctnr) {}
	[...]
};

int main()
{
	std::vector<int> vector_std;
	for (int i = 0; i <= 10; i++)
        	vector_std.push_back(i);
	
   	std::stack<int, std::vector<int> > stack_std = vector_std;
}

...

>> error: no viable conversion [...] explicit constructor is not a candidat.

```
**3. friend:** allows a function to access private and protected members of a class.  
```
template <class T, class Container>
class stack {
	private:
		Container _container;
	public:
		friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return (lhs._container == rhs._container);
		}
	[...]
};

```
## Namespaces 👨🏻‍🚀🚀  
  
#### std::equal  
https://en.cppreference.com/w/cpp/algorithm/equal  
  
#### std::lexicographical_compare  
https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare  
  
#### std::is_integral  
https://en.cppreference.com/w/cpp/types/is_integral  
https://learn.microsoft.com/fr-fr/cpp/cpp/char-wchar-t-char16-t-char32-t?view=msvc-170  
  
#### std::pair / std::make_pair  
https://cplusplus.com/reference/utility/pair/pair/  
https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a02030.html  
  
#### std::enable_if  
https://eli.thegreenplace.net/2014/sfinae-and-enable_if/  
  
#### std::iterator_traits  
https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits  
  
## Usefull documentation 🗃️  
https://en.cppreference.com/w/cpp/container/vector  
