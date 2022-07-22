
#pragma once

#include "types.hpp"

namespace union_find{

    class UnionFind
    {

    public:

        UnionFind(u64 node_count);

        ~UnionFind();

        void unite(u64 id);

        bool connected(u64 id);

        static bool connected(u64 id1, u64 id2);

        u64 find();

        u64 count();

    private:
        const u64 m_node_count;

    };


    class QuickFind {

        constexpr QuickFind( const isize count ) {
            constexpr Array<isize, count> i;

//            std::make_unique<Array<isize, count>>();
        }


    private:
        static const isize m_count;
        std::unique_ptr<Array<isize,m_count>> Array<isize, m_count>;

    };

    class QuickUnion {

    };


}


