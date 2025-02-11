class SparseElement:

    def __init__(self, row, col, value):

        self.row = row
        self.col = col
        self.value = value

        return None


class SparseMatrix:
    def __init__(self, rows, cols):
        self.elements = []
        self.rows = rows
        self.cols = cols

    def _find_element(self, row, col): #class k ander hi use ho rha h sirff isiliye underscore se suru ho rha
        for element in self.elements:
            if element.row == row and element.col == col:
                return element
        return None

    def set_value(self, row, col, value):
        existing_element = self._find_element(row, col)
        if existing_element: # if existing_element is not None
            if value == 0:
                self.remove_value(row, col) # convert by calling remove_val
            else:
                existing_element.value = value
        elif value != 0:
            self.elements.append(SparseElement(row, col, value))

    def get_value(self, row, col):
        element = self._find_element(row, col)
        return element.value if element else 0

    def add_value(self, row, col, value):
        element = self._find_element(row, col)
        if element:
            element.value += value
            if element.value == 0:
                self.remove_value(row, col)
        elif value != 0:
            self.elements.append(SparseElement(row, col, value))

    def remove_value(self, row, col):
        element = self._find_element(row, col)
        if element:
            self.elements.remove(element)

    def get_num_rows(self):
        return self.rows

    def get_num_cols(self):
        return self.cols

    def get_transposed_matrix(self):
        transposed_matrix = SparseMatrix(self.cols, self.rows)
        for element in self.elements:
            transposed_matrix.set_value(element.col, element.row, element.value)
        return transposed_matrix

    def get_scalar_product(self, factor):
        for element in self.elements:
            element.value *= factor

    def get_matrix_sum(self, other):
        if self.rows != other.rows or self.cols != other.cols:
            raise ValueError("Matrices dimensions do not match.")
        for element in other.elements:
            self.add_value(element.row, element.col, element.value)

    def get_matrix_product(self, other):
        if self.cols != other.rows:
            raise ValueError("Matrices dimensions do not match for multiplication.")
        result = SparseMatrix(self.rows, other.cols)
        for element in self.elements:
            for col in range(other.cols):
                value = self.get_value(element.row, col) * other.get_value(element.col, col)
                if value != 0:
                    result.add_value(element.row, col, value)
        return result

    def get_dense_array(self):
        dense_array = [[0 for _ in range(self.cols)] for _ in range(self.rows)] # List Coprehension/ Underscore is valid name not relvent name required / it will put 0
        for element in self.elements:
            dense_array[element.row][element.col] = element.value
        return dense_array


def test_sparse_matrix():
    sm = SparseMatrix(4, 5)

    sm.set_value(0, 1, 7)
    sm.set_value(2, 3, 15)
    sm.set_value(1, 4, 22)

    assert sm.get_value(0, 1) == 7, "Value at (0, 1) should be 7"
    assert sm.get_value(2, 3) == 15, "Value at (2, 3) should be 15"
    assert sm.get_value(1, 4) == 22, "Value at (1, 4) should be 22"
    assert sm.get_value(3, 3) == 0, "Value at (3, 3) should be 0 (not set)"

    sm.add_value(2, 3, 5)  # Increment existing value
    sm.add_value(3, 0, 10) # Set new value

    assert sm.get_value(2, 3) == 20, "Value at (2, 3) should be updated to 20"
    assert sm.get_value(3, 0) == 10, "Value at (3, 0) should be 10"

    sm.remove_value(0, 1)
    sm.remove_value(3, 0)

    assert sm.get_value(0, 1) == 0, "Value at (0, 1) should be removed (0)"
    assert sm.get_value(3, 0) == 0, "Value at (3, 0) should be removed (0)"

    assert sm.get_num_rows() == 4, "Number of rows should be 4"
    assert sm.get_num_cols() == 5, "Number of cols should be 5"

    print("All tests passed!")

if __name__ == "__main__":
    test_sparse_matrix()
