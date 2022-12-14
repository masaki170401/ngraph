//*****************************************************************************
// Copyright 2017-2020 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

// this is for more nuanced testing
class TestMatcher : public ngraph::pattern::Matcher
{
    using ngraph::pattern::Matcher::Matcher;
    bool virtual match_node(const std::shared_ptr<ngraph::Node>& pattern_node,
                            const std::shared_ptr<ngraph::Node>& graph_node,
                            PatternMap& pattern_map) override
    {
        if (ngraph::as_type_ptr<::ngraph::op::Parameter>(pattern_node))
        {
            bool result = pattern_node == ngraph::as_type_ptr<::ngraph::op::Parameter>(graph_node);
            if (result)
            {
                m_matched_list.push_back(graph_node);
            }
            return result;
        }

        return this->ngraph::pattern::Matcher::match_node(pattern_node, graph_node, pattern_map);
    }

public:
    bool match(const std::shared_ptr<ngraph::Node>& pattern_node,
               const std::shared_ptr<ngraph::Node>& graph_node)
    {
        NGRAPH_CHECK(pattern_node && graph_node); // the same condition throws an exception in the
                                                  // non-test version of `match`
        NGRAPH_DEBUG << "Starting match pattern = " << pattern_node->get_name()
                     << " , graph_node = " << graph_node->get_name();

        m_pattern_map.clear();
        m_match_root.reset();
        m_matched_list.clear();

        bool is_match = match_node(pattern_node, graph_node, m_pattern_map);
        if (is_match)
        {
            m_match_root = graph_node;
        }
        return is_match;
    }
};
