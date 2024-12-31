#include <iostream>
#include <vector>
using namespace std;

void printDouble(double d) {
    if (abs(d) < 1e-7)
        cout << 0.0;
    else
        cout << d;
}

struct Point {
    double x, y, z;
};

struct Particle {
    Point p, v;
    double m;
};

Point neg(const Point& p) { return {-p.x, -p.y, -p.z}; }

// Pre:
// Post: returns the sum of p1 and p2.
Point sum(const Point& p1, const Point& p2) {
    return {p1.x + p2.x, p1.y + p2.y, p1.z + p2.z};
}

// Pre:
// Post: returns a times p.
Point mul(double a, const Point& p) { return {a * p.x, a * p.y, a * p.z}; }

struct World {
    vector<Particle> particles;
    int t;
};

Point centerOfMass(const World& world) {
    Point p = {0, 0, 0};
    double m = 0;
    for (const Particle& particle : world.particles) {
        p = sum(p, mul(particle.m, particle.p));
        m += particle.m;
    }
    return mul(1 / m, p);
}

void step(World& world, int time) {
    for (Particle& particle : world.particles) {
        particle.p = sum(particle.p, mul(time, particle.v));
    }
    world.t += time;
}

void printPoint(const Point& p) {
    printDouble(p.x);
    cout << " ";
    printDouble(p.y);
    cout << " ";
    printDouble(p.z);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(5);

    int n, k;
    while (cin >> n >> k) {
        World world;
        world.particles.reserve(n);

        for (int i = 0; i < n; ++i) {
            double x, y, z, vx, vy, vz, m;
            cin >> x >> y >> z >> vx >> vy >> vz >> m;
            Particle particle = {{x, y, z}, {vx, vy, vz}, m};
            world.particles.push_back(particle);
        }

        Point cof = centerOfMass(world);
        Point cof_dir;
        {
            World world_cpy = world;
            step(world_cpy, 1);
            Point center = centerOfMass(world_cpy);
            cof_dir = sum(center, neg(cof));
        }

        int iterations = 0;
        for (int i = 0; i < k; ++i) {
            int t;
            cin >> t;
            cof = sum(cof, mul(t, cof_dir));
            printPoint(cof);
            iterations += t;
        }

        step(world, iterations);

        for (int i = 0; i < n; ++i) {
            printPoint(world.particles[i].p);
        }

        cout << '\n';
    }

    return 0;
}
