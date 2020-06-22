#pragma once

#include "frpch.h"

#include "Fresh/Events/Event.h"

namespace Fresh {

	class Layer {

	public:
		Layer(const std::string& name = "Layer");

		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_Name; }

	private:
		std::string m_Name;
	};

}