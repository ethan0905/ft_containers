# ft_containers 📦📦📦 [![esafar's 42 ft_containers Score](https://badge42.vercel.app/api/v2/cl6l739qg00490gialxmtgsrk/project/2852806)](https://github.com/JaeSeoKim/badge42)
  
## 📔 Summary

 - [📚 Containers/Algorithm/Iterators](#-containersalgorithmiterators)
 - [⏱️ Strat for ft_containers ](#%EF%B8%8F-strat-for-ft_containers)
 - [🔨 Tools](#-tools-typedef-explicit-friend)
 - [❗️ Potential mistakes !](#%EF%B8%8F-potential-mistakes-)
 - [⚙️ How to run the project ?](#%EF%B8%8F-how-to-run-the-project-)
 - [🗃️ Usefull documentation](#%EF%B8%8F-usefull-documentation)
  
## 📚🔢📐 Containers/Algorithm/Iterators  
#### In C++ STL (Standard Template Library), 3 things are meaningful and important:  
  
**1. Containers:** These are used to manage collection of objects of a certain kind. Containers can be of two types: Sequence Containers (vector, deque, list) and Associative Containers (Set, Multiset, Map, Multimap).  
**2. Algorithms:** These are used to process the elements of a collection. That is algorithms feed from containers and process those elements in a predefined way and may also push the results into the same/different container.  
**3. Iterator:** These are used to step through the elements of collection of objects (aka containers).  
  
## ⏱️ Strat for ft_containers  

At first, I didn't know where to start on this project. I spent quite some time thinking about an effective strategy, in order to finish the project faster. The following instructions are precious, and gives you an easy to understand roadmap.
  
1. Start by coding all the following std functions, asked in the subject (you gonna be able to use them later, inside your containers)
	- equal
	- lexicographical_compare
	- is_integral
	- pair
	- make_pair
	- enable_if
	- iterator_traits
	- reverse_iterator
2. Then, begin coding stack as your first container, and use original vector from STL to test it.  
3. When your stack container works properly. start coding vector container and test it with your previously handmade stack container.  
4. Final step, code map and drop a star on this repo for the time I saved you ;)    
  
## 🔨 Tools (typedef, explicit, friend)  
  
**1. typedef:** allows to give a new name to an existing data type.  
````c++
template <class T, ...>
class stack {
	public:
		typedef T value_type;
		
		value_type& top() {
   			return (_container.back());
		}
	[...]
};
````

**1.bis typename:** let the compiler know that Iter is a type and not a static member of std::vector  
````c++
  
typedef typename std::vector<T>::iterator Iter  
  
````

**2. explicit:** allows only direct-initialization (avoid implicit conversions and copy initialization from braced-init-list).  
````c++
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

````
**3. friend:** allows a function to access private and protected members of a class.  
````c++
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

````

## ❗️ Potential mistakes !
#### Error: this file requires compiler and library support... for c++ 2011 standard [...]
````shell
/usr/include/c++/11/bits/c++0x_warning.h:32:2: error: #error This file requires compiler and library support for the ISO C++ 2011 standard. This support must be enabled with the -std=c++11 or -std=gnu++11 compiler options.
   32 | #error This file requires compiler and library support \
      |  ^~~~~
````
To fix this, you should check in your files that you are not including libraries from c++11 that are not supported and which block compilation with the c++98 standard.  
In my case, I forgot this include in my is_integral file:  
````c++
#include <iostream>
// #include <type_traits>     <- this include is from c++11
````
And here you go!
#### Error: invalide type argument of unary '*' (have int)
````shell
vector.hpp:52:31: error: invalid type argument of unary ‘*’ (have ‘int’)
   52 |                     push_back(*it);
      |                               ^~~
      
inside this specific constructor:  
template<class InputIterator>
vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0) {
	for (InputIterator it = first; it != last; it++)
        	push_back(*it);
}
````
To fix this, you gonna need to use enable_if to check if the user pass as a 4th parameter an iterator, that has the type of an integral integer (is_integral)
````c++
typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL
````
And here you done !  
  
## ⚙️ How to run the project ?

1. Clone the repository:  
`git clone https://github.com/ethan0905/ft_containers.git`  
2. Compile the project:  
`make -j`  
3. Run the program:  
`./ft_containers`  
4. Enjoy ;)  
  
## 🗃️ Usefull documentation  
### std functions
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

### containers
#### vector
https://en.cppreference.com/w/cpp/container/vector  
