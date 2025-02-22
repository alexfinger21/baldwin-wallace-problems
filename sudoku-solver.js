/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */

const nums = []

for (let i = 0; i<9; ++i) {
    nums.push(String(i+1))
}

var solveSudoku = function(board) {
    let poss = new Array(9)
    for (let i = 0; i<9; ++i) {
        poss[i] = new Array(9)
        for (let j = 0; j<9; ++j) {
            poss[i][j] = new Set()
        }
    }

    let squares = new Array(9)
    for (let i = 0; i<9; ++i) {
        squares[i] = new Array(9)
        for (let j = 0; j<9; ++j) {
            squares[i][j] = board[Math.floor(i/3)*3+Math.floor(j/3)][(i%3)*3 + j%3]
        }
    }
    const upd = function() {
        poss = new Array(9)
        for (let i = 0; i<9; ++i) {
            poss[i] = new Array(9)
            for (let j = 0; j<9; ++j) {
                poss[i][j] = new Set()
            }
        }
        for (let i = 0; i<9; ++i) {
            for (let j = 0; j<9; ++j) {
                if (board[i][j] == '.') {
                    //console.log(i, j)
                    const sqr = Math.floor(i/3)*3 + Math.floor(j/3)
                    for (const idx of squares[sqr]) {
                        if (idx != ".") {
                            poss[i][j].add(idx)
                        }
                    }

                    for (let c = 0; c<9; ++c) {
                        if (board[i][c] != '.') {
                            poss[i][j].add(board[i][c])
                        }
                    }

                    for (let r = 0; r<9; ++r) {
                        if (board[r][j] != '.') {
                            poss[i][j].add(board[r][j])
                        }
                    }
                    //console.log(poss[i][j], squares[sqr])
                }
            }
        }
    }

    const solv = function() {
        upd()
        let prevUnsolved = 0
        let unsolvedCount = 1
        while (unsolvedCount && !(prevUnsolved == unsolvedCount)) {
            prevUnsolved = unsolvedCount
            unsolvedCount = 0;
            for (let i = 0; i<9; ++i) {
                for (let j = 0; j<9; ++j) {
                    if (board[i][j] == '.') {
                        if (poss[i][j].size >= 8) {
                            const missing = nums.find(n => !poss[i][j].has(n))  
                            if (!missing) {
                                if (i == 6 && j == 6) {
                                    //console.log("====", board, "====")
                                }
                                return 0
                            }
                            board[i][j] = missing
                            poss[i][j].add(missing)

                            const sqr = Math.floor(i/3) * 3 + Math.floor(j/3)
                            //console.log(missing, squares[sqr], poss[i][j], i, j)
                            const idx = (i - Math.floor(i/3) * 3) * 3 + j - Math.floor(j/3)*3
                            squares[sqr][idx] = missing 
                            upd()
                        } else {
                            ++unsolvedCount
                        }
                    }
                }
            }
            
        }
        if (unsolvedCount) {
            return 1
        }
        return 2
    }
    let step = 0
    const superSolve = function() {
        const stepp = step
        ++step
        const sRes = solv()
        //if (board[0][6] == "6") {
            //console.log("SRES", step, sRes)
        //}
        if (sRes == 0) {
            return -1
        } else if (sRes == 1) {
            let mx = 0, mxi = []
            for (let i = 0; i<9; ++i) {
                for (let j = 0; j<9; ++j) {
                    if (poss[i][j].size < 8 && poss[i][j].size > mx) {
                        mx = poss[i][j].size
                        mxi = [i, j]
                    }
                }
            }

            const nms = nums.filter(n => !poss[mxi[0]][mxi[1]].has(n))

            const boardd = JSON.parse(JSON.stringify(board))
            const squaress = JSON.parse(JSON.stringify(squares))


            for (const n of nms) {
                board = boardd
                squares = squaress
                //console.log(n, mxi, "====", board[mxi[0]][mxi[1]], poss[mxi[0]][mxi[1]])
                board[mxi[0]][mxi[1]] = n
                const r = superSolve()
                if (board[0][7] == "5") {
                    console.log(mxi, n, r, stepp, "og", boardd, "new", board)
                }
                if (r != -1) {
                    return 1
                }
            }
            return -1
        }
        return 1
    }
    superSolve()
};
