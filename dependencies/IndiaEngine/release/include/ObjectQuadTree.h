#pragma once
#include "Core.h"
#include "Object.h"
#include "BoxCollider.h"

#include <vector>
#include <memory>

namespace India {

	template class India_EXPORT std::allocator<Object*>;
	template class India_EXPORT std::vector<Object*>;

	class India_EXPORT ObjectQuadtree {

	public:
		static const int MAX_DEPTH = 10;
		ObjectQuadtree() noexcept;
		ObjectQuadtree(const BoxCollider& boundary, int capacity) noexcept;
		ObjectQuadtree(const BoxCollider& boundary, int capacity, int level) noexcept;
		~ObjectQuadtree();
		/**
		Inserts object pointer into the tree.
		*/
		void Insert(Object& object);
		/**
		Recursive Query that returns all objects that intersect within the specified range.
		*/
		std::vector<std::reference_wrapper<Object>> Query(const BoxCollider& range, std::vector<std::reference_wrapper<Object>> found_objects = {}) const noexcept;
		/**
		Recursively returns all boundaries.
		*Useful for visualising the quadtree.
		*/
		std::vector<Rectangle> GetBoundaries(std::vector<Rectangle> rectangles = {}) const noexcept;
		/**
		returns level of the deepest node.
		*/
		int Depth() const noexcept;
	private:
		bool _divided;
		India::BoxCollider _boundary;
		int _capacity;
		int _level;
		std::vector<std::reference_wrapper<Object>> _objects;

		std::unique_ptr<ObjectQuadtree> _north_west;
		std::unique_ptr<ObjectQuadtree> _north_east;
		std::unique_ptr<ObjectQuadtree> _south_west;
		std::unique_ptr<ObjectQuadtree> _south_east;

		/**
		*
		Divides section in 4 child quadtrees.
		After a quadtree is subdivided, all the objects contained by it will be transferred to the subdivided children.
		*/
		void Subdivide() noexcept;

		int Depth(int lowest_level) const noexcept;
	};

}