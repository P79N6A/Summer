import React from 'react';
import { Tag } from 'antd';
import './App.css';
import 'antd/dist/antd.css';

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      collapsed: false,
    };
  }
  onCollapse (collapsed){
    console.log(collapsed);
    this.setState({ collapsed });
  }
  render() {
    return (
      <div className="main">
        <Tag color="magenta">magenta</Tag>
        <Tag color="lime">lime</Tag>
      </div>
    );
  }
}

export default App;
