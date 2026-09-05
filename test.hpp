template <typename T>
class balls {
    public:
        T _val;
        balls(T&& t);
        T add(T& n) const;
};
