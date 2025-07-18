/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */

const nums = []

for (let i = 0; i<9; ++i) {
    nums.push(String(i+1))
}

var solveSudoku = function(bb) {
    
    const upd = function(board) {
        const squares = new Array(9)
        for (let i = 0; i<9; ++i) {
            squares[i] = new Array(9)
            for (let j = 0; j<9; ++j) {
                squares[i][j] = board[Math.floor(i/3)*3+Math.floor(j/3)][(i%3)*3 + j%3]
            }
        }
        const poss = new Array(9)
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
        return poss
    }

    const solv = function(board) {
        
        const poss = upd(board)

        let dots = 0
        let mx = 0, mxi = []
        for (let i = 0; i<9; ++i) {
            for (let j = 0; j<9; ++j) {
                if (board[i][j] == '.') {
                    ++dots
                }
                if (board[i][j] == '.' && poss[i][j].size > mx) {
                    mx = poss[i][j].size
                    mxi = [i, j]
                }
            }
        }

        const nms = nums.filter(n => !poss[mxi[0]][mxi[1]].has(n))
        
        if (nms.length) {
            //console.log(dots, mxi, nms)
            if (dots == 1) {
                const board_cp = JSON.parse(JSON.stringify(board))
                board_cp[mxi[0]][mxi[1]] = nms[0]
                //console.log(board_cp)
                return board_cp
            }
            for (let k = 0; k<nms.length; ++k) {
                if (nms.length > 1) {
                    //console.log(nms, nms[k])
                }
                const board_cp = JSON.parse(JSON.stringify(board))
                board_cp[mxi[0]][mxi[1]] = nms[k]
                const r = solv(board_cp)
                if (r != -1) {
                    return r
                }
            }
        } 

        return -1
    }

    const bb_c = solv(bb)
    //console.log("BIBIBABA",bb_c)

    for (let i = 0; i<9; ++i) {
        for (let j = 0; j<9; ++j) {
            bb[i][j] = bb_c[i][j]
        }
    }
};
