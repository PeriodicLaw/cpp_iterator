# cpp_iterator

用C++实现Rust风格的迭代器（玩具级别）。包括：

- `Option<T>` 类
- （基于CRTP的） `Iterator` 基类
- （数值）范围迭代器 `make_range`
- 从STL容器创建迭代器 `from_container`
- `map` `chain` `zip` 等迭代器组合子
- `foreach` 等其他泛型函数

[例子](examples)