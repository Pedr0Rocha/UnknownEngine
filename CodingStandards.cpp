/* namespace starts with lowercase */
namespace ukn {
	/* class starts with uppercase */
	class Unknown {
		/* attribute starts with uppercase */
		int AttributeOne;
		int AttributeTwo;
		
		/* member function starts with lowercase */
		void printAttr(int varOne) {
			/* local variable starts with lowercase */
			std::cout << AttributeOne << " " << AttributeTwo << " " << varOne << std::endl;
		}
	};
}

/* function starts with uppercase */
void PrintClassAttr() {
	ukn::Unknown objUnk;
	objUnk.printAttr(5);
}

int main() {
	std::cout << "Coding Standards" << std::endl;
	PrintClassAttr();
	return 0;
}