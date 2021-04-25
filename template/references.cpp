// 1 dimentional container
template<
        template<typename...> class C,
        typename... Args
>
void print(C<Args...> container) {
    cout << "[";
    for (auto it = container.cbegin(); it != container.cend();)
        cout << *it << (++it != container.cend() ? ", " : "");
    cout << "]\n";
}

// 2 dimensional container
template<
        template<typename...> class C,
        typename... Args
>
void print(C<Args...> container) {
    cout << "[\n";
    for (const auto &innerContainer: container) {
        cout << "  [";
        for (auto it = innerContainer.cbegin(); it != innerContainer.cend();)
            cout << *it << (++it != innerContainer.cend() ? ", " : "");
        cout << "]\n";
    }
    cout << "]\n";
}
