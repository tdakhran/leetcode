#!/usr/bin/env python3

import numpy as np
from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def contains_duplicated_numbers(e) -> bool:
            e = e[e != '.']
            return len(e) != len(set(e))

        board = np.array(board)
        for index in range(9):
            row = board[index, :]
            if contains_duplicated_numbers(row):
                return False
            col = board[:, index]
            if contains_duplicated_numbers(col):
                return False
        for r, c in zip(range(3), range(3)):
            quad = board[3 * r:3 * r+3, 3 * c:3 * c+3]
            if contains_duplicated_numbers(quad):
                return False
        return True
