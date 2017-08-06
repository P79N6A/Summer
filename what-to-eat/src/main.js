import React from 'react';
import ReactDom from 'react-dom';

import App from './component/App.js';
import './component/App.css';

import { DatePicker } from 'antd';
import 'antd/dist/antd.css';

ReactDom.render(<App className="app-container"/>, document.getElementsByClassName('J_container')[0]);