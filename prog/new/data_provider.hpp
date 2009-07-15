#ifndef BA_DATA_PROVIDER_HPP
#define BA_DATA_PROVIDER_HPP

namespace ba
{

    namespace
    {
        template <>
        struct count
        {
            static const unsigned value = 0;
        };

        template <typename T, typename... Args>
        struct count
        {
            static const unsigned value = 1 + count<Args...>::value;
        };
    }


    // Eigentlich muss hier auch noch der Typ übergeben werden,
    // aber es reicht erstmal, wenn alles double ist. Nur der
    // vector_data_provider benötigt überhaupt ints

    template <typename T, typename FilterT = void>
    class data_provider
    {
    public:
        template <typename... Args>
        data_provider (Args const& args)
        {
            // get count<Args> elements of type T::type
        }

        void* operator-> () { return *(*this); }

        void* operator* ()
        {
            if (current_entry_ != test_base::get_current_entry())
                current_entry_ = test_base::refresh(ptr_);

            return ptr_;
        }

    private:
        T* ptr_ = 0;
        int current_entry_ = -1;
    };


    template <typename T, typename FilterT>
    class vector_data_provider
    {
    public:
        template <typename... Args>
        vector_data_provider (Args const&... args)
        {
        }

        T const& operator[] (int index)
        {
        }

    private:
        int current_entry_;
    };

}

#endif
