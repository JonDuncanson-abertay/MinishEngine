#include "PhysicsCollider.h"

namespace minish
{
	PhysicsCollider::PhysicsCollider() : m_collision_callback(nullptr)
	{}

	PhysicsCollider::~PhysicsCollider()
	{}

	const std::vector<sf::Vector2f>& PhysicsCollider::getPointList() const
	{
		return m_points;
	}

	const std::vector<sf::Vector2f>& PhysicsCollider::getTransformedPointList() const
	{
		return m_transformed_points;
	}

	void PhysicsCollider::setCollisionCallback(void (*callback)())
	{
		m_collision_callback = callback;
	}

	void PhysicsCollider::transformPoints(const sf::Transform& transform)
	{
		for (unsigned int i = 0; i < m_points.size(); i++)
		{
			m_transformed_points[i] = transform.transformPoint(m_points[i]);
		}
	}
	void PhysicsCollider::addPoint(const sf::Vector2f& point)
	{
		for (auto it = m_points.begin(); it != m_points.end(); it++)
		{
			if ((*it) == point)
				return;
		}

		m_points.push_back(point);
		m_transformed_points.resize(m_points.size());
	}

	void PhysicsCollider::removePoint(const sf::Vector2f& point)
	{
		auto pos = m_points.end();
		for (auto it = m_points.begin(); it != m_points.end(); it++)
		{
			if ((*it) == point)
			{
				pos = it;
				break;
			}
		}

		if (pos != m_points.end())
			m_points.erase(pos);

		m_transformed_points.resize(m_points.size());
	}
}