#pragma once

#include "frpch.h"

#include "Layer.h"

namespace Fresh {

	class LayerStack {

		typedef std::vector<Layer*>::iterator LayerIterator;

	public:

		LayerStack() = default;
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		LayerIterator begin() { return m_Layers.begin(); }
		LayerIterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		uint32_t m_LayerInsertIndex = 0;
	};

}
