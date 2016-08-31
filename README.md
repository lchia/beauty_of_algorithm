These code comes from "Beauty of Algorithm, Zuo Fei (C++ version)".
===================================================================

Why I made this repo?
---------------------
`Some of the codes in the book are wrong`, for example: example 4.3.4 (Page 108), which was named "c04_list/magic_card.cpp".  

The error was modified in the "magic_card.cpp", where I labeled with _"modified by lch (50~62)"_.

All the codes comes from the [web support](http://blog.csdn.net/baimafujinji/article/details/50602547)

How to use the code?
--------------------
All the codes were tested on `Ubuntu 16.04` using g++, for example:  
*$ cd c04_list/*  
**$ g++ magic_card.cpp -o magic_card**  
***$ ./magic_card***  
and it will print as following:  
***1,5,2,9,10,3,13,7,8,4,6,12,11***  
which is the order of the 13 cards.  

The example of the modified code:
-----------------------------
```cpp
if(poker.GetCur() == head) { //Added by lch (50~62): I found '9' located 'head', which 'SetData()' not work
         cout << "     @@node: This is 'head', cannot assign a 'value', so just go on next." << endl;
         cout << "       ->link : " << poker.GetCur()->GetLink() << endl;
         cout << "       ->data : " << poker.GetCur()->GetData() << endl;
         for (int j=0; j<1; j++) {
                 poker.GetNext();
                 cout << "     j->" << j << ": link->" << poker.GetCur()->GetLink() << "; data->" << poker.GetCur()->GetData() << endl; 
                 if(poker.GetCur()->GetData() != 0) {
                         j--;
                 }
         }
 }
```
  
The cover of this book:
------------------------
![](https://github.com/lchia/beauty_of_algorithm/beauty_of_algorithm.png)

