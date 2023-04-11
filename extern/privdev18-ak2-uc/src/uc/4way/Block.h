/**
 \file 		Block.h
 \author 	guenther@rangar.de
 \copyright	Valiant's Universal Circuit Construction Optimized for Private Function Evaluation
			Copyright (C) 2016 Engineering Cryptographic Protocols Group, TU Darmstadt
			This program is free software: you can redistribute it and/or modify
			it under the terms of the GNU Affero General Public License as published
			by the Free Software Foundation, either version 3 of the License, or
			(at your option) any later version.
			This program is distributed in the hope that it will be useful,
			but WITHOUT ANY WARRANTY; without even the implied warranty of
			MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
			GNU Affero General Public License for more details.
			You should have received a copy of the GNU Affero General Public License
			along with this program. If not, see <http://www.gnu.org/licenses/>.
 \brief		Header of the Block class part of Valiant's 4-way Split Construction.
 */

#ifndef VALIANTUC4WAYSPLIT_BLOCK_H
#define VALIANTUC4WAYSPLIT_BLOCK_H

#include <vector>
#include <map>
#include <stdint.h>
#include <algorithm>
#include "UCNode.h"
#include "NodeType.h"
#include "BlockType.h"

class Block {

 public:
  const uint32_t DUMMY = 9;

  std::vector<std::vector<UCNode*>>& getRecursionPoints();
  uint32_t getSize() const;

  void setInputPermutationBit(uint32_t input, uint32_t position);
  void setOutputPermutationBit(uint32_t output, uint32_t position);

  virtual void edgeEmbedding(const std::map<uint32_t, uint32_t>& mapping) = 0;
  virtual bool validateEdgeEmbedding(int eugNumber) = 0;

  virtual void printEmbedding() = 0;

  std::vector<UCNode*> getPoles();

 protected:
  std::vector<UCNode*> poles;
  std::map<uint32_t, UCNode*> nodes;

  // [x][y]
  // 0 <= x <= 3 (0:q, 1:r, 2:s, 3:t)
  // 0 <= y <= 1 ([0][y] = q_{i + y}
  std::vector<std::vector<UCNode*>> recursionPoints;
  std::vector<uint32_t> recursionSteps;
  uint32_t position;
  BlockType blockType;

  std::vector<uint32_t> inputPermutation;
  std::vector<uint32_t> outputPermutation;

  void createEdge(UCNode* parent, UCNode* child);
  void createNodesFromTo(uint32_t from, uint32_t to, NodeType nodeType);
  };

Block* createBlock(std::vector<UCNode*> poles, uint32_t poleIndex, std::vector<uint32_t> recursionSteps, uint32_t position,
                   BlockType blockType, std::vector<std::vector<UCNode*>> recursionPoints, uint32_t k, bool zhao);

#endif //VALIANTUC4WAYSPLIT_BLOCK_H
