package week1


class WeightedQuickUnionTest {

    WeightedQuickUnion wqu =  new WeightedQuickUnion(10)

    void testConnected() {
        assert (!wqu.connected(1 , 2))
    }

    void testUnion() {
    }
}
