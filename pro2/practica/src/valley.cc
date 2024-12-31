/** @file valley.cc

    @brief Contiene las definiciones de la clase `Valley`
*/
#include "valley.hh"
#include <unordered_map>

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

static void printRiverImpl(BinTree<std::string> river, int level) {
    using namespace std;

    if (river.empty()) return;

    cout << string(level * 2, ' ');
    cout << river.value() << endl;

    printRiverImpl(river.left(), level + 1);
    printRiverImpl(river.right(), level + 1);
}

static std::vector<Product> sProducts;
const std::vector<Product>& Valley::getProducts() { return sProducts; }
size_t Valley::numProducts() { return sProducts.size(); }

BinTree<string> Valley::readRiverImpl(
    std::unordered_map<std::string, City>& cityMap) {
    using namespace std;

    std::string node;
    cin >> node;

    if (node == "#") return BinTree<std::string>();

    cityMap[node] = City(node);

    BinTree<std::string> left = readRiverImpl(cityMap);
    BinTree<std::string> right = readRiverImpl(cityMap);

    return BinTree<string>(node, left, right);
}

void Valley::readRiver() {
    using namespace std;

    mCities = std::unordered_map<std::string, City>();
    mShip.last_travels = std::vector<std::string>();
    mCityNames = readRiverImpl(mCities);
}

void Valley::readShip() {
    using namespace std;

    int id1, count1, id2, count2;
    cin >> id1 >> count1 >> id2 >> count2;

    if ((id1 - 1) >= sProducts.size() || (id2 - 1) >= sProducts.size()) {
        cout << "error: no existe el producto" << endl;
        return;
    }

    if (id1 == id2) {
        cout << "error: no se puede comprar y vender el mismo producto" << endl;
        return;
    }

    mShip.buy_id = id1;
    mShip.sell_id = id2;
    mShip.buy_count = count1;
    mShip.sell_count = count2;
}

void Valley::printShip() const {
    using namespace std;
    cout << mShip.buy_id << " " << mShip.buy_count << " " << mShip.sell_id
         << " " << mShip.sell_count << endl;

    for (const auto& name : mShip.last_travels) {
        cout << name << '\n';
    }
    flush(cout);
}

void Valley::addProducts(int quantity) {
    using namespace std;

    for (int i = 0; i < quantity; i++) {
        int w, v;
        cin >> w >> v;
        sProducts.emplace_back(Product(w, v));
    }
}

bool Valley::isValidProduct(size_t id) const {
    return (id - 1) < sProducts.size();
}

void Valley::printProduct(int index) const {
    using namespace std;

    if (!(index < sProducts.size())) {
        cout << "error: no existe el producto" << endl;
        return;
    }

    cout << index + 1 << ' ' << sProducts[index].weight << ' '
         << sProducts[index].volume << endl;
}

void Valley::readCityInventory(const std::string& name) {
    using namespace std;
    mCities[name].clearInventory();

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int id, has, need;
        cin >> id >> has >> need;

        // if (name == "yegcx")
        //     cout << id << ' ' << has << ' ' << need << endl;

        mCities[name].setProductInventory(id - 1, has, need);
    }
}

void Valley::addToCityInventory(const std::string& name, size_t id, int has,
                                int needs) {
    mCities[name].setProductInventory(id - 1, has, needs);
}

void Valley::removeFromCityInventory(const std::string& name, size_t id) {
    mCities[name].removeProduct(id - 1);
}

bool Valley::isValidCity(const std::string& name) const {
    return mCities.find(name) != mCities.end();
}

bool Valley::hasProduct(const std::string& name, size_t id) const {
    return mCities.at(name).has(id - 1);
}

void Valley::printCity(const std::string& name) const {
    mCities.at(name).print();
}

void Valley::getCityMassVol(const std::string& name, int& mass,
                            int& vol) const {
    mCities.at(name).getTotalMassVol(mass, vol);
}

void Valley::getCityProduct(const std::string& name, size_t id, int& mass,
                            int& vol) const {
    mCities.at(name).getProduct(id - 1, mass, vol);
}

void Valley::printRiver() const { printRiverImpl(mCityNames, 0); }

void Valley::trade(const std::string& city1, const std::string& city2) {
    City& c1 = mCities[city1];
    City& c2 = mCities[city2];

    auto it1 = c1.begin();
    auto it2 = c2.begin();
    while (it1 != c1.end() && it2 != c2.end()) {
        if (*it1 == *it2) {
            size_t id = *it1;
            // If both cities have a surplus, there is no trade
            if (c1.surplus(id) && c2.surplus(id)) {
                it1++;
                it2++;
                continue;
            }
            if (!c1.surplus(id) && !c2.surplus(id)) {
                it1++;
                it2++;
                continue;
            }

            if (c1.surplus(id)) {
                int needs = c2.needs(id);
                int surplus_count = c1.surplusCount(id);

                int trade_count = std::min(needs, surplus_count);
                c1.addProducts(id, -trade_count);
                c2.addProducts(id, trade_count);
            } else {
                int needs = c1.needs(id);
                int surplus_count = c2.surplusCount(id);

                int trade_count = std::min(needs, surplus_count);
                c1.addProducts(id, trade_count);
                c2.addProducts(id, -trade_count);
            }

            it1++;
            it2++;
        } else if (*it1 < *it2)
            it1++;
        else
            it2++;
    }
}

void Valley::redistribute() { redistImpl(mCityNames); }

void Valley::redistImpl(const BinTree<std::string>& root) {
    bool do_left = !root.left().empty();
    bool do_right = !root.right().empty();
    if (do_left) {
        trade(root.value(), root.left().value());
    }

    if (do_right) {
        trade(root.value(), root.right().value());
    }

    if (do_left) {
        redistImpl(root.left());
    }

    if (do_right) {
        redistImpl(root.right());
    }
}

void Valley::travel() {
    RouteData best_route_data;
    auto best_route = findBestRoute(best_route_data, mCityNames,
                                    mShip.buy_count, mShip.sell_count);
    std::cout << best_route_data.total() << std::endl;

    // printRiver();

    // Perform route in reverse as directions vector is in reverse bc of
    // recursion
    BinTree<std::string> curr = mCityNames;
    // For some reason copying this object (including the vector inside) is
    // faster (and pases efficiency) than just extracting only the 2 ints needed
    // (which does not pass efficiency).
    Ship ship = mShip;
    size_t buy_id = mShip.buy_id - 1;
    size_t sell_id = mShip.sell_id - 1;
    int i = best_route.size() - 1;
    while (i >= 0) {
        // 1. Perform trade
        City& c = mCities[curr.value()];
        if (c.needs(sell_id) > 0 && ship.sell_count > 0) {
            int trade_count = std::min(c.needs(sell_id), ship.sell_count);
            c.addProducts(sell_id, trade_count);
            ship.sell_count -= trade_count;
        }

        if (c.surplus(buy_id) && ship.buy_count > 0) {
            int trade_count = std::min(c.surplusCount(buy_id), ship.buy_count);
            c.addProducts(buy_id, -trade_count);
            ship.buy_count -= trade_count;
        }

        // 2. Go up-river
        if (best_route.at(i) == Ship::Direction::Left) {
            curr = curr.left();
        } else {
            curr = curr.right();
        }

        i--;
    }

    // 3. Perform last trade
    City& c = mCities[curr.value()];
    if (best_route_data.total() > 0) mShip.last_travels.push_back(c.getName());
    if (c.needs(sell_id) > 0 && ship.sell_count > 0) {
        int trade_count = std::min(c.needs(sell_id), ship.sell_count);
        c.addProducts(sell_id, trade_count);
    }

    if (c.surplus(buy_id) && ship.buy_count > 0) {
        int trade_count = std::min(c.surplusCount(buy_id), ship.buy_count);
        c.addProducts(buy_id, -trade_count);
    }
}

std::vector<Ship::Direction> Valley::findBestRoute(
    RouteData& data, const BinTree<std::string>& root, int buy_count,
    int sell_count) {
    // 0. Base case (Reached end of tree)
    if (root.empty()) {
        return std::vector<Ship::Direction>();
    }

    // 0.5 Early exit case (Ship sold and bought everything)
    if (sell_count <= 0 && buy_count <= 0) {
        return std::vector<Ship::Direction>();
    }

    // 1. Calculate buy and sell quantity in current city
    City c = mCities[root.value()];  // Get copy of current city

    size_t buy_id = mShip.buy_id - 1;
    size_t sell_id = mShip.sell_id - 1;

    if (c.needs(sell_id) > 0 && sell_count > 0) {
        int trade_count = std::min(c.needs(sell_id), sell_count);
        sell_count -= trade_count;
        data.sell_count += trade_count;
    }

    if (c.surplus(buy_id) && buy_count > 0) {
        int trade_count = std::min(c.surplusCount(buy_id), buy_count);
        buy_count -= trade_count;
        data.buy_count += trade_count;
    }

    // 2. Calculate best routes from left and right
    RouteData best_left_data;
    auto best_left =
        findBestRoute(best_left_data, root.left(), buy_count, sell_count);
    RouteData best_right_data;
    auto best_right =
        findBestRoute(best_right_data, root.right(), buy_count, sell_count);

    // 2.5 If no trades have happened early return here with current trades
    if (best_left_data.total() == 0 && best_right_data.total() == 0)
        return std::vector<Ship::Direction>();

    // 3. Choose best route (left or right)
    Ship::Direction choosed_dir = Ship::Direction::None;
    if (best_right_data.total() > best_left_data.total())
        choosed_dir = Ship::Direction::Right;
    else if (best_left_data.total() > best_right_data.total())
        choosed_dir = Ship::Direction::Left;
    // Equal
    else if (best_right.size() < best_left.size())
        choosed_dir = Ship::Direction::Right;
    else
        choosed_dir = Ship::Direction::Left;

    // 4. Update and return calculated best route
    if (choosed_dir == Ship::Direction::Left) {
        data.buy_count += best_left_data.buy_count;
        data.sell_count += best_left_data.sell_count;
        best_left.push_back(choosed_dir);  // Route is defined back to front
        return best_left;
    } else {
        data.buy_count += best_right_data.buy_count;
        data.sell_count += best_right_data.sell_count;
        best_right.push_back(choosed_dir);  // Route is defined back to front
        return best_right;
    }
}
