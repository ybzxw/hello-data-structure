# ifndef _HELLO_VECTOR_H_
# define _HELLO_VECTOR_H_
typedef int Rank;                            // 秩
#define DEFAULT_CAPACITY 3                   // 默认初始容量


template <typename T> 
class Vector{
protected:
    Rank _size;                              // 规模
    int _capacity;                           // 容量
    T* _elem;                                // 元素
    
    void copy_from(T const* A, 
        Rank lo, Rank hi);                   // 赋值数组区间A[lo, hi]
    void expand();                           // 扩容
    void shrink();                           // 压缩
    bool bubble(Rank lo, Rank hi);           // 扫描交换
    void bubble_sort(Rank lo, Rank hi);      // 冒泡排序算法
    Rank max(Rank lo, Rank hi);              // 选取最大元素
    void selection_sort(Rank lo, Rank li);   // 选择排序算法
    void merge(Rank lo, Rank mi, Rank li);   // 归并算法
    void merge_sort(Rank lo, Rank li);       // 归并排序算法
    Rank partition(Rank lo, Rank hi);        // 轴点构造算法
    void quick_sort(Rank lo, Rank hi);       // 快速排序算法
    void heap_sort(Rank lo, Rank hi);        // 堆排序

public:
    // 构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0): _elem(new T[_capacity = c])
    { for (_size = 0; _size < s; _elem[_size++] = v); }
    // 数组区间复制
    Vector(T const* A, Rank lo, Rank hi) { copy_from(A, lo, hi); }
    // 数组整体复制
    Vector(T const* A, Rank n) { copy_from(A, 0, n); }
    // 向量区间复制
    Vector(Vector<T> const& V, Rank lo, Rank hi) { copy_from(V._elem, lo, hi); }
    // 向量整体复制
    Vector(Vector<T> const& V) { copy_from(V._elem, 0, V._size); } 

    // 析构函数
    ~Vector() { delete [] _elem; } 
    // 只读访问接口
    const Rank size() const { return _size; }                          // 返回大小
    const bool empty() const { return !_ size; }                       // 是否为空
    const int disordered() const;                                      // 判断是否排序
    const Rank find(T const& e) const { return find(e, 0, _size); }    // 无序向量整体查找
    const Rank find(T const& e, Rank lo, Rank hi) const;               // 无序向量范围查找
    const Rank search(T const& e) const                                // 有序向量整体查找
        { return (0 >= _size) ? -1 : search(e, 0, _size); }
    const Rank search(T const& e, Rank lo, Rank hi) const              // 无序向量范围查找
        { return (0 >= _size) ? -1 : search(e, lo, hi); }
    
    // 可写访问接口
    T& operator [] (Rank r) const;                                     // 重载下标运算符
    Vector<T> & operator=(Vector<T> const&);                           // 重载复制下标运算符
    T remove(Rank r);                                                  // 删除秩为r的元素
    int remove(Rank lo, Rank hi);                                      // 删除秩在区间[lo, hi)之内的元素
    Rank insert(Rank r, T const& e);                                   // 插入元素
    Rank insert(T const& e) { return insert(_size, e); }               // 默认作为末元素插入
    void sort(Rank lo, Rank hi);                                       // 对[lo, hi)排序
    void sort() { sort(0, _size); }                                    // 整体排序
    void unsort(Rank lo, Rank hi);                                     // 对[lo, hi)置乱
    void unsort() { unsort(0, _size); }                                // 整体置乱
    int deduplicate();                                                 // 无序去重
    int uniquify();                                                    // 有序去重

    // 遍历
    void traverse(void(*)(T&));                                        // 遍历
    template<typename VST>
    void traverse(VST&);                                               // 遍历                    
}; 

#endif