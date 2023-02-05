
// Created by W0L1D on 12/20/2022.

#include <chrono>
#include "BTree.h"
#include "Pair.h"
#include "BigInt.h"

using namespace std;



//template<typename keyType, typename valueType>
//valueType fibonucci_tree(keyType n, BTree<Pair<keyType, valueType>> &v) {
//    if (n < 0)
//        throw std::invalid_argument("Invalide nomber > 0");
//
//    if (n == 0 || n == 1)
//        return n;
//
//    Node<Pair<keyType, valueType>> *node = nullptr;
//    if ((node
//                 = v.findNode(
//                    make_pair2<keyType, valueType>(n, 0)
//            ))
//        != nullptr)
//        return node->data.second;
//
//
//    valueType a = fibonucci_tree(n - 1, v), b = fibonucci_tree(n - 2, v);
//    valueType result;
//    auto p = make_pair2<keyType, valueType>(n, (result = a + b));
//    v.insert(p);
//    return result;
//}

template <typename T1, typename T2>
T2 fibonacci_avl(long n, BTree<Pair<T1, T2>> *tree) {
    if (n == 0) {
        return BigInt("0");
    }

    if (n == 1) {
        return BigInt("1");
    }
    auto *p = new Pair<T1, T2>(n, BigInt("0"));

    if (auto fib_pair = tree->search(*p)) {
        return fib_pair->data.second;
    }

    T2 fib = fibonacci_avl(n-1, tree) + fibonacci_avl(n-2, tree);
    p->second = fib;
    tree->insert(*p);

    return fib;
}

void testTreeWithMaxElement(long long max) {
    auto *tree1 = new BTree<long long >();

    auto start = chrono::high_resolution_clock::now();
    for (long long i = 1; i <= max; ++i) {
        tree1->insert(i);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "L'insertion de "<< max <<" elements a pris " << duration.count() << " ms" <<endl;
    cout << tree1->size() << " elements sont inserees" << endl;



    delete tree1;

    cout<< endl;
}


int main() {
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);


    // Test d'un million
//    testTreeWithMaxElement(1000*1000);
//
//    //Test de 10 Million
//    testTreeWithMaxElement(1000*1000*10);
//
//    //Test de 100 Million
//    testTreeWithMaxElement(1000*1000*100);

    //Test de 1 bilion
    testTreeWithMaxElement(1000*1000*1000);

    cout << "presse any key to continue...\n\n";
    getchar();
    auto tree = new BTree<Pair<long long, BigInt>>();

    while (1) {
        long n;
        cout << "Entrer la valeur (-1 pour quitter): ";
        cin >> n;
        if (n == -1)
            break;
        cout << endl;

        auto start = chrono::high_resolution_clock::now();
        cout << "\nresultat : " << fibonacci_avl(n, tree) << "\n\n";

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Le calcule avec arbre binaire a pris : " << duration.count() << " ms" <<endl;
    }

    cout << "Good Bye" << endl;
    return 0;
}