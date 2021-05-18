#include "GameObject.h"

Gameobject::Gameobject(const std::string& Name)
{
	m_Name = Name;
}

void Gameobject::updateModelMatrix()
{
	m_ModelMatrix = m_TranslationMatrix * m_TranslationMatrix * m_ScaleMatrix;
}
