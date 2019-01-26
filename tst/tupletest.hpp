class TestHelper {
private:
	int n;

	bool copied{false};
	bool moved{false};

public:
	TestHelper(int const n = 0) noexcept: n{n} {}

	TestHelper(TestHelper const &) noexcept = default;
	TestHelper(TestHelper &&) noexcept = default;

	TestHelper &operator =(TestHelper const &th) noexcept {
		n = th.n;
		copied = true;
		return *this;
	}

	TestHelper &operator =(TestHelper &&th) noexcept {
		n = std::move(th.n);
		moved = true;
		return *this;
	}

	operator int() const noexcept {
		return n;
	}

	bool isCopied() const noexcept {
		return copied;
	}

	bool isMoved() const noexcept {
		return moved;
	}
};

auto getPerson() {
	TestHelper const th{146};
	std::string const name{"Petia"};
	std::string const secondName{"Ivanoff"};
	std::size_t const age{23};
	std::string const department{"Sale"};
	return custom_make_tuple(th, name, secondName, age, department);
}

void checkcopy() {
	TestHelper th;
	std::string name, secondName, department;
	std::size_t age;
	auto const person{getPerson()};

	custom_tie(th, name, secondName, age, department) = person;

	EXPECT_EQ(th, 146);
	EXPECT_TRUE(th.isCopied());
	EXPECT_FALSE(th.isMoved());
	EXPECT_EQ(name, "Petia");
	EXPECT_EQ(secondName, "Ivanoff");
	EXPECT_EQ(age, 23);
	EXPECT_EQ(department, "Sale");
}

void checkmove() {
	TestHelper th;
	std::string name, secondName, department;
	std::size_t age;

	custom_tie(th, name, secondName, age, department) = getPerson();

	EXPECT_EQ(th, 146);
	EXPECT_FALSE(th.isCopied());
	EXPECT_TRUE(th.isMoved());
	EXPECT_EQ(name, "Petia");
	EXPECT_EQ(secondName, "Ivanoff");
	EXPECT_EQ(age, 23);
	EXPECT_EQ(department, "Sale");
}
