import React from 'react';
import ReactDom from 'react-dom';

import App from './component/App.js';

import { DatePicker } from 'antd';
import 'antd/dist/antd.css';

ReactDom.render(<App />, document.getElementsByClassName('J_container')[0]);