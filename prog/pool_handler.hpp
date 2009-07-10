#ifndef BA_POOL_HANDLER_HPP
#define BA_POOL_HANDLER_HPP

namespace ba
{

    template <typename T>
    class pool_handler
    {
    public:
        pool_handler(std::string const& name)
            : obj(test::get_ref_to<T>(name))
        {
        }

        T& obj;
    };

    template <typename T>
    class vector_pool_handler
    {
    public:
        vector_pool_handler()
        {
        }

        template <typename... Args>
        vector_pool_handler(std::string const& name, Args... const& args)
        {
            handlers_.push_back(pool_handler<T>(name));
            vector_pool_handler(args);
        }

        T const& operator[] (int i) const
        {
            return handlers_[i].obj;
        }
    };
}

#endif
